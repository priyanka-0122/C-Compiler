#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//Token structure
struct token {
        int token;
        int intvalue;
};

//Tokens
enum {
        T_EOF, T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};
	
// AST node types
enum {
	A_ADD, A_SUBTRACT, A_MULTIPLY, A_DIVIDE, A_INTLIT
};

// Abstract Sysntx Tree structure
struct ASTnode {
	int op;				// "Operation to be performed on tthis tree
	struct ASTnode *left;		// Left child tree
	struct ASTnode *right;		// Right child tree
	int intvalue;			// For A_INTLIT, the integer value
};
