#include "defs.h"
#include "data.h"
#include "decl.h"

// List of avalable registers and their names
static int freereg[4];
static char *reglist[4] = { "%r8", "%r9", "%r10", "%r11" };
static char *breglist[4] = { "%r8b", "%r9b", "%r10b", "%r11b" };

// Set all registers as available
void freeall_registers(void)
{
	freereg[0]= freereg[1]= freereg[2]= freereg[3] = 1;
}

// Allocate a free register. Return the number of the register. Die if no available registers.
static int alloc_register(void)
{
	for (int i=0; i<4; i++) {
		if (freereg[i]) {
			freereg[i] = 0;
			return(i);
		}
	}
	fatal("Out of registers!");
}

// Return a register to the list of available registers. Check to see if it's not already there
static void free_register(int reg)
{
	if (freereg[reg] != 0)
		fatald("Error trying to free register", reg);
	freereg[reg] = 1;
}

// Print out the assembly preamble
void cgpreamble()
{
	freeall_registers();
	// Only print out the code for printint()
	  fputs("\t.text\n"
	".LC0:\n"
	"\t.string\t\"%d\\n\"\n"
	"printint:\n"
	"\tpushq\t%rbp\n"
	"\tmovq\t%rsp, %rbp\n"
	"\tsubq\t$16, %rsp\n"
	"\tmovl\t%edi, -4(%rbp)\n"
	"\tmovl\t-4(%rbp), %eax\n"
	"\tmovl\t%eax, %esi\n"
	"\tleaq	.LC0(%rip), %rdi\n"
	"\tmovl	$0, %eax\n"
	"\tcall	printf@PLT\n" "\tnop\n" "\tleave\n" "\tret\n" "\n", Outfile);
}

// Print out a function preamble
void cgfuncpreamble(char *name) {
	fprintf(Outfile,
		"\t.text\n"
		"\t.globl\t%s\n"
		"\t.type\t%s, @function\n"
		"%s:\n" "\tpushq\t%%rbp\n"
		"\tmovq\t%%rsp, %%rbp\n", name, name, name);
}

// Print out a function postamble
void cgfuncpostamble() {
	fputs("movl $0, %eax\n" "\tpopq	%rbp\n" "\tret\n", Outfile);
}

// Load an integer literal value into a register. Return the number of the register
int cgloadint(int value, int type) {

	// Get a new register
	int r = alloc_register();

	// Print out the code to initialise it
	fprintf(Outfile, "\tmovq\t$%d, %s\n", value, reglist[r]);
	return(r);
}

// LOad a value form a variable into a register. Return the number of the register
int cgloadglob(int id) {
	// Get a new register
	int r = alloc_register();

	// Print out the code to initialise it: P_CHAR or P_INT
	if (Gsym[id].type == P_INT)
		fprintf(Outfile, "\tmovq\t%s(\%%rip), %s\n", Gsym[id].name, reglist[r]); //movq moves 8-bytes into the 8-byte register
	else
		fprintf(Outfile, "\tmovzbq\t%s(\%%rip), %s\n", Gsym[id].name, reglist[r]); //movzbq zeroes the 8-byte register and then moves a single byte into it
	return (r);
}

// Add two registers together and return the number of the register with the result
int cgadd(int r1, int r2) {
	fprintf(Outfile, "\taddq\t%s, %s\n", reglist[r1], reglist[r2]);
	free_register(r1);
	return(r2);
}

// Multiply two registers together and return the number of the register with the result
int cgmul(int r1, int r2) {
	fprintf(Outfile, "\timulq\t%s, %s\n", reglist[r1], reglist[r2]);
	free_register(r1);
	return(r2);
}

// Subtract the second register from the first and return the number of the register with the result
int cgsub(int r1, int r2) {
	fprintf(Outfile, "\tsubq\t%s, %s\n", reglist[r2], reglist[r1]);
	free_register(r2);
	return(r1);
}

//Divide the first register by the second and return the number of the register with the result
int cgdiv(int r1, int r2) {
	fprintf(Outfile, "\tmovq\t%s, %%rax\n", reglist[r1]);	//dividend is loaded to %rax
	fprintf(Outfile, "\tcqo\n");				//cqo is used to extend to eight bytes
	fprintf(Outfile, "\tdivq\t%s\n", reglist[r2]);		//idivq divides the content in %rax with 
								//the r2 and stores quotient in %rax
	fprintf(Outfile, "\tmovq\t%%rax,%s\n", reglist[r1]);
	free_register(r2);
	return(r1);
}

void cgprintint(int r) {
	fprintf(Outfile, "\tmovq\t%s, %%rdi\n", reglist[r]); 	//Linux x86-64 expects te first arg to
								// a function to be %rdi
	fprintf(Outfile, "\tcall\tprintint\n");
	free_register(r);
}

// Store a register's value into a variable
int cgstorglob(int r, int id) {
	// Choose P_INT or P_CHAR
	if (Gsym[id].type == P_INT)
		fprintf(Outfile, "\tmovq\t%s, %s(\%%rip)\n", reglist[r], Gsym[id].name);
	else
		fprintf(Outfile, "\tmovb\t%s, %s(\%%rip)\n", breglist[r], Gsym[id].name); // movb used to move a single byte
	return (r);
}

// Generate a global symbol
void cgglobsym(int id) {
	// Choose P_INT or P_CHAR
	if (Gsym[id].type == P_INT)
		fprintf(Outfile, "\t.comm\t%s,8,8\n", Gsym[id].name);
	else
		fprintf(Outfile, "\t.comm\t%s,1,1\n", Gsym[id].name);
}

// List of comparisons instructions in AST order:
// A_EQ, A_NE, A_LT, A_GT, A_LE, A_GE
static char *cmplist[] = { "sete", "set", "setl", "setg", "setle", "setge"};

// Compare two registers and set if trues.
int cgcompare_and_set(int ASTop, int r1, int r2) {

	//Check two randge of the AST operation
	if (ASTop < A_EQ || ASTop > A_GE)
		fatal("Bad ASTop in cgcompare_and_set()");

	fprintf(Outfile, "\tcmpq\t%s, %s\n", reglist[r2], reglist[r1]);
	fprintf(Outfile, "\t%s\t%s\n", cmplist[ASTop - A_EQ], breglist[r2]);
	fprintf(Outfile, "\tmovzbq\t%s, %s\n", breglist[r2], reglist[r2]);
	free_register(r1);
	return (r2);
}

// Generate a label
void cglabel(int l) {
	fprintf(Outfile, "L%d:\n",l);
}

// Generate a jump to a label
void cgjump(int l) {
	fprintf(Outfile, "\tjmp\tL%d\n", l);
}

// List of inverted jump instructions in AST order:
// A_EQ, A_NE, A_LT, A_GT, A_LE, A_GE
static char *invcmplist[] = { "jne", "je", "jge", "jle", "jg", "jl" };

// Compare two registers and jump if false.
int cgcompare_and_jump(int ASTop, int r1, int r2, int label) {

	// Check the range of the AST operation
	if(ASTop < A_EQ || ASTop > A_GE)
		fatal("Bad ASTop in cgcompare_and_Set()");

	fprintf(Outfile, "\tcmpq\t%s, %s\n", reglist[r2], reglist[r1]);
	fprintf(Outfile, "\t%s\tL%d\n", invcmplist[ASTop - A_EQ], label);
	freeall_registers();
	return (NOREG);
}

// Widen the value in the register from the old to the new type, and return a register with this new value
int cgwiden (int r, int oldtype, int newtype) {
	// Nothing to do
	return r;
}
