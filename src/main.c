#include <stdio.h>
#include "header/data.h"
#include <stdlib.h>
#include "header/scan.h"
#include <math.h>
#include "header/ast.h"
#include "header/symtable.h"


#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


int Line = 1;
int Putback = 0;
struct Token* currentToken = NULL;
FILE* Infile = NULL;
FILE* Outfile = NULL;
char Text[TEXTLEN + 1] = { NULL };
LinkedList* globl_symtable[SYMTABLE_SIZE] = { NULL };
struct Token* globl_putback_token = NULL;
struct VAR_STACK* globl_var_stack = NULL;


static void initGloblVar()
{
	currentToken = malloc(sizeof(struct Token));
	Line = 1;
	Putback = 0;
}

// todo:  fix bugs:  (-x) * y  && var q;   q = ...; && undef statement && (1   /2);

// todo: free tokens

int main(int argc, char* argv[])
{
	initGloblVar();
	const char* fileName = "test.txt";
	LinkedList* tokenList = newLinkedList();


	Infile = fopen(fileName, "r");
	if (Infile != NULL)
	{
		globl_var_stack = mkVarStack();
		varStack_push_frame();  // globl frame
		struct AST_Node* ast_root = genMainAST(0);
		interpretMainAST(ast_root);

#if 0
		struct AST_Node* curNode = ast_root->right;
		printf("curNode:  %d\n", curNode->tokenType);
#endif

		/*
		int** intArr = calloc(50, sizeof(int));
		if (intArr[65] == NULL)
		{
			printf("NULL\n");
		}
		*/

		exit(0);
	}

	printf("[ERROR] could not open file '%s'\n", fileName);

	exit(1);
}
