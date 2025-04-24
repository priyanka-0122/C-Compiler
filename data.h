#ifndef extern_
 #define extern_ extern
#endif

//extern_ is a custom extension of extern
extern_ int Line;		// Current line number			
extern_ int Putback;		// Character put back by scanner
extern_ int Functionid;		// Symbol id of the current function
extern_ int Globs;		// Position of the next free global symbol slot
extern_ int Locls;		// Position of next free local symbol slot
extern_ FILE *Infile;		// Input file
extern_ FILE *Outfile;		// Output file
extern_ char *Outfilename;      // Name of file we opened as Outfile
extern_ struct token Token;	// Last token scanned
extern_ char Text[TEXTLEN + 1];	// Last identifier scanned
extern_ struct symtable Symtable[NSYMBOLS];	//Global symbol table

extern_ int O_dumpAST;
extern_ int O_keepasm;          // If true, keep any assembly files   
extern_ int O_assemble;         // If true, assemble the assembly files
extern_ int O_dolink;           // If true, link the object files     
extern_ int O_verbose;          // If true, print info on compilation stages
