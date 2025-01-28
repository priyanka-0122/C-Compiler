#ifndef DEFS_H
	#include "defs.h"
#endif
#define extern_
#ifndef DATA_H
	#include "data.h"
#endif
#undef extern_
#ifndef DECL_H
        #include "decl.h"
#endif

//List of printable tokens
char *tokstr[] = {"+", "-", "*", "/", "intlit" };

//Loop scanning in all the tokens in the input file
//Print out details of each token found
static void scanfile() {
	struct token T;

	while (scan(&T)) {
		printf("Token %s", tokstr[T.token]);
		if (T.token == T_INTLIT)
			printf(", value %d", T.intval);
		printf("\n");
	}
}

void main(int argc, char *argv[]) {

//	init();
	if (argc != 2) {
		printf("Expected number of input is 2\nexample: ./scanner <filename>\n");
		exit(0);
	}

	Line = 1;
       	Putback = '\n';
	Infile = fopen(argv[1], "r");
	
	///Checking if the file is open or not
	if (Infile == NULL) {
		printf("The file is not opened\n");
		exit(0);
	}
	scanfile();
	fclose(Infile);
	exit(0);
}
