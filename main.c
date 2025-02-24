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

void main(int argc, char *argv[]) {
	struct ASTnode *n;
	
	if (argc != 2) {
		fprintf(stderr, "Usage: %s infile", argv[0]);
		exit(1);
	}

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

	scan(&Token);		// Get the first token from the input
	genpreamble();		// Output the preamble
	statements();		// Parse the statements in the input
	genpostamble();		// Output the postamble
	
	fclose(Outfile);
	fclose(Infile);
	exit(0);
}
