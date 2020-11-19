#ifndef AST_H
#define AST_H
#include "tokens.h"
#include "symtable.h"
#include <stdio.h>
#include<limits.h>
#include<stdint.h>
#include<stdlib.h>

#define INTERRUPT_TOKEN_DEFAULT -1

struct AST_Node
{
	INT_VAL intVal;
	double floatVal;
	int tokenType;
	struct AST_Node* left;
	struct AST_Node* right;
	void* otherData;
	const char* varName;
	struct DATA_STRUCT* data;
};


struct AST_Node* mkastnode(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, struct AST_Node* right, void* otherData, struct DATA_STRUCT* data);
struct AST_Node* mkastnode_const(int tokenType, INT_VAL intVal, double floatVal, void* otherData, struct DATA_STRUCT* data);
struct AST_Node* mkastnode_left(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, void* otherData, struct DATA_STRUCT* data);
struct AST_Node* mkastnode_ident(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, struct AST_Node* right, void* otherData, const char* varName, struct DATA_STRUCT* data);

struct AST_Node* binexpr();

struct DATA_STRUCT* interpretAST_int(struct AST_Node* root);
struct AST_Node* binexpr_int(int ptp, int interrupt_token);

struct AST_Node* genMainAST();
void interpretMainAST(struct AST_Node* root);

struct AST_Node* genVarAST();
struct AST_Node* genIdentAST();
struct AST_Node* genCMP_AST();



#endif
