#include <stdio.h>
#include "header/stringFunct.h"
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
LinkedList* globl_symtable = NULL;


static void initGloblVar()
{
	currentToken = malloc(sizeof(struct Token));
	Line = 1;
	Putback = 0;
	currentToken = malloc(sizeof(struct Token));
	globl_symtable = newLinkedList();
}


// todo: free tokens

int main(int argc, char* argv[])
{
	initGloblVar();
	const char* fileName = "test.txt";
	LinkedList* tokenList = newLinkedList();
	
	Infile = fopen(fileName, "r");
	if (Infile != NULL)
	{  
		struct AST_Node* ast_root = genMainAST();


		//printf("test:  %s\n", ast_root->varName);

		interpretMainAST(ast_root);

		/*struct IDENT_tokenData* testID = symtable_getItem("y");
		printf("res::  %s\n", testID->varName);*/


		/*struct IDENT_tokenData* testID = newID_token(4, 5, 434, "test");
		struct IDENT_tokenData* testID2 = newID_token(4, 5, 434, "test2");
		symtable_add("test", testID);
		symtable_add("test2", testID2);
		struct IDENT_tokenData* retID1 = symtable_getItem("test");
		struct IDENT_tokenData* retID2 = symtable_getItem("test2");

		printf("testId:  %s\n", retID2->varName);*/



		exit(0);
	}

	printf("[ERROR] could not open file '%s'\n", fileName);
	
	exit(1);
}