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

void main(int argc, char *argv[]) {
	struct ASTnode *tree;

	usage(argc, argv[0]);
	init();	

	Infile = fopen(argv[1], "r");
	//Checking if the file is open or not
	if (Infile == NULL) {
		fprintf(stderr, "Unable to open %s: %s\n",argv[1], strerror(errno));
		exit(1);
	}
	
	// Create the output file
	Outfile = fopen("out.s", "w");
	if (Outfile == NULL) {
		fprintf(stderr, "Unable to open %s: %s\n",argv[1], strerror(errno));
		exit(1);
	}

	scan(&Token);			// Get the first token from the input
	genpreamble();			// Output the preamble
	tree = compound_statement();	// Parse the statements in the input
	genAST(tree, NOREG, 0);		// Generate the assembly code for it
	genpostamble();			// Output the postamble
	
	fclose(Outfile);
	fclose(Infile);
	exit(0);
}
