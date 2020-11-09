#include <stdio.h>
#include "header/stringFunct.h"
#include "header/data.h"
#include <stdlib.h>
#include "header/scan.h"
#include <math.h>
#include "header/ast.h"
#include "header/symtable.h"

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

struct Test
{
	const char* n;
};


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

		struct AST_Node* cNode = ast_root->right;
		//struct IDENT_token* otherData =(struct AST_Node*) ast_root->otherData;
		printf("main:   %s\n", ast_root->varName);


		exit(0);
	}

	printf("[ERROR] could not open file '%s'\n", fileName);
	
	exit(1);
}