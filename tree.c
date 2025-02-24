#include "defs.h"
#include "data.h"
#include "decl.h"

// Build and return a generic AST node
struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int intvalue) {
	struct ASTnode *n;
	
	//Calloc a new ASTnode
	n = (struct ASTnode *)calloc(1, sizeof(struct ASTnode));
	if (n == NULL) {
		fprintf(stderr, "Unable to calloc a node in mkastnode()\n");
		exit(1);
	}
	
	// Copy in the field values and return it
	n->op = op;
	n->left = left;
	n->right = right;
	n->intvalue = intvalue;
	return (n);
}

// Make an AST leaf node
struct ASTnode *mkastleaf(int op, int intvalue) {
	return (mkastnode(op, NULL, NULL, intvalue));
}

// Make a unary AST node with only one child
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue) {
	return (mkastnode(op, left, NULL, intvalue));
}
