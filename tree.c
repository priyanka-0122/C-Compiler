#include "defs.h"
#include "data.h"
#include "decl.h"

// Build and return a generic AST node
struct ASTnode *mkastnode(int op, int type,
			struct ASTnode *left, struct ASTnode *mid, struct ASTnode *right,
			int intvalue) {
	struct ASTnode *n;
	
	//Calloc a new ASTnode
	n = (struct ASTnode *)calloc(1, sizeof(struct ASTnode));
	if (n == NULL) {
		fprintf(stderr, "Unable to calloc a node in mkastnode()\n");
		exit(1);
	}
	
	// Copy in the field values and return it
	n->op = op;
	n->type = type;
	n->left = left;
	n->mid = mid;
	n->right = right;
	n->v.intvalue = intvalue;
	return (n);
}

// Make an AST leaf node
struct ASTnode *mkastleaf(int op, int type, int intvalue) {
	return (mkastnode(op, type, NULL, NULL, NULL, intvalue));
}

// Make a unary AST node with only one child
struct ASTnode *mkastunary(int op, int type, struct ASTnode *left, int intvalue) {
	return (mkastnode(op, type, left, NULL, NULL, intvalue));
}
