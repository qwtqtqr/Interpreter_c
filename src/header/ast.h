#ifndef AST_H
#define AST_H
#include "tokens.h"
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


struct IDENT_token
{
	int dataType;
	int hasValue;
	INT_VAL value;
	const char* varName;
};


static struct IDENT_token* newIdentToken(int dataType, int hasValue, INT_VAL value, const char* varName)
{
	struct IDENT_token* initT = malloc(sizeof(struct IDENT_token));
	initT->dataType = dataType;
	initT->hasValue = hasValue;
	initT->value = value;
	initT->varName;
	return initT;
}


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