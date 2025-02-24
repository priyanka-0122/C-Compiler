#ifndef extern_
 #define extern_ extern
#endif

//extern_ is a custom extension of extern
extern_ int Line;		// Current line number			
extern_ int Putback;		// Character put back by scanner
extern_ FILE *Infile;		// Input file
extern_ FILE *Outfile;		// Output file
extern_ struct token Token;	// Last token scanned
extern_ char Text[TEXTLEN +1];	// Last identifier scanned
