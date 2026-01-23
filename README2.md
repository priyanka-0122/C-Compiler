1. R0-R7 is related to temporary storage in case if we need to store intermediate results as in case of the below expression for the inside braces expression
			  int z= (a + b) * (c - d) / (e + f) * (g + h - i) * (q - 3);
		Or something like printf("%d\n", b + 3); where '"3" is a temporary value
2. sp_adjust keeps track of how many bytes are pushed on the stack every time we push any byte or pop any byte
3. Compilation phases
	wcc is a frontend that co-ordinates all the phases.
	Preprocessor interprets pre-processor							_cpp
	Lexer produces a token stream	 			cscan				_tok
	Parser creates a symbol table plus a set of AST trees	cparse6809 or cparseqbe		_sym and _ast
	Code generator generates assembly code	 		cgen6809 or cgenqbe		_qbe
	Peephole optimizer improves the assembly code	 	cpeep				_s
	External assembler produces object files
	External linker	takes crt0.o, the object files and libraries and produces final executable
4. serialiseAST() writes the given node and its children out to disk i.e. ast file in this case. Each time there is a single statement, we parse this statement, build up the AST tree for it and then dump it to disk. There isn't enough memory to build the AST tree for a function, then write it out (or read it in)
5. serialiseSym() writes a symbol table node and any associated string out to the file i.e. sym file in this case. One optimisation is that, as nodes are given montonically increasing ids, we can record the highest symbol id we have already written out, and not (re)write symbols at or below this id
	a. flushSymtable() in sym.c walks the type list and the generic symbol list and calls serialiseSym().
	b. freeSym() frees the memory that a symbol entry occupies.
4. fgetstr() in https://github.com/DoctorWkt/acwj/blob/master/64_6809_Target/tree.c#L236 is used for reading word by word and alse fgetstr() is just a modified version of fread() used to read back the size of each struct i.e till NUL-terminated string
5. The symbol table and ASTnode information is written to the idx file using fwrite() as we are using lesser space size.
6. Both the symbol table structure and the ASTnode structure now have numeric ids beacuse when dumping in-memory structures out to disk the pointers in the structures lose their meaning: when the structure is reloaded, it's going to end up in another part of memory. Any pointer value becomes invalid.
7. Offset informs where my node starts in the AST_file


The below case are still needed to be fixed
	a. Long's maximum value is also same as integer need to increase the range for long
	b. Handling sizeof wrt 6809 -> input126.c, input162.c
	c. Handling sizeof wrt QBE -> input162.c
