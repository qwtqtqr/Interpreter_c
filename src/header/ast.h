#ifndef AST_H
#define AST_H
#include "tokens.h"
#include "symtable.h"
#include "data.h"
#include <stdio.h>
#include<limits.h>
#include<stdint.h>
#include<stdlib.h>

#define INTERRUPT_TOKEN_DEFAULT -1
#define SCOPE_MODE_DEFAULT 0
#define SCOPE_MODE_STATEMENT 1

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


struct DATA_STRUCT* interpretAST_binexpr(struct AST_Node* root);
struct AST_Node* binexpr(int ptp, int interrupt_token);

struct AST_Node* genMainAST(int scope_depth, int scope_mode, int if_init);
void interpretMainAST(struct AST_Node* root);

struct AST_Node* genVarAST();
struct AST_Node* genIdentAST();


void varStack_push_frame();
struct VAR_STACK* varStack_getFrame();
void stackFrame_add_var(char* varName);
void varStack_pop_frame();
struct VAR_STACK* mkVarStack();



#endif