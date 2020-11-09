#ifndef AST_H
#define AST_H
#include "tokens.h"
#include "symtable.h"
#include <stdio.h>


struct AST_Node
{
	INT_VAL intVal;
	double floatVal;
	int tokenType;
	struct AST_Node* left;
	struct AST_Node* right;
	void* otherData;
	const char* varName;
};


enum
{
	DT_INT,
	DT_DOUBLE,
	DT_FLOAT,
	DT_CHAR,
	DT_STRING,
	DT_BOOL,
};

struct AST_Node* mkastnode(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, struct AST_Node* right, void* otherData);
struct AST_Node* mkastnode_const(int tokenType, INT_VAL intVal, double floatVal, void* otherData);
struct AST_Node* mkastnode_left(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, void* otherData);
struct AST_Node* mkastnode_ident(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, struct AST_Node* right, void* otherData, const char* varName);

struct AST_Node* binexpr();

INT_VAL interpretAST_int(struct AST_Node* root);
struct AST_Node* binexpr_int(int ptp);

struct AST_Node* genMainAST();
void interpretMainAST(struct AST_Node* root);

struct AST_Node* genVarAST();



#endif