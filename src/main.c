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


static void initGloblVar()
{
	currentToken = malloc(sizeof(struct Token));
	Line = 1;
	Putback = 0;
	currentToken = malloc(sizeof(struct Token));
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
		interpretMainAST(ast_root);


		/*
		int** intArr = calloc(50, sizeof(int));
		if (intArr[65] == NULL)
		{
			printf("NULL\n");
		}
		*/

		/*long double test = 0.1;
		//printf("%Lf\n", test);
		printf("%.27Lg\n", test);*/


		exit(0);
	}

	printf("[ERROR] could not open file '%s'\n", fileName);

	exit(1);
}
