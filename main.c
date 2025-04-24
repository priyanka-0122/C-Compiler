#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>

static void init() {
	Line = 1;
	Putback = '\n';
}

static void usage(int argc, char *prog)
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s infile", prog);
		exit(1);
	}
}

int main(int argc, char *argv[]) {
	struct ASTnode *tree;

	usage(argc, argv[0]);
	init();	

	// Open up the input file
	if ((Infile = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Unable to open %s: %s\n",argv[1], strerror(errno));
		exit(1);
	}
	
	// Create the output file
	if ((Outfile = fopen("out.s", "w")) == NULL) {
		fprintf(stderr, "Unable to open %s: %s\n",argv[1], strerror(errno));
		exit(1);
	}

	// For now, ensure that void printint() is defined
	addglob("printint", P_CHAR, S_FUNCTION, 0);

	scan(&Token);				// Get the first token from the input
	genpreamble();				// Output the preamble
	while (1) {				// Parse a function
		tree = function_declaration();
		genAST(tree, NOREG, 0);		// Generate the assembly code for it
		if (Token.token == T_EOF)	// Stop when we reached EOF
			break;
	}
	genpostamble();
	fclose(Outfile);
	fclose(Infile);
	return(0);
}
