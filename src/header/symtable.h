#include <stdio.h>
#include "tokens.h"
#include "list.h"

#pragma once

#define SYMTABLE_SIZE 5000

extern LinkedList* globl_symtable[SYMTABLE_SIZE];


struct IDENT_tokenData
{
	char* varName;
	int dataType;
	int init;
	INT_VAL value;
	int var;
	struct DATA_STRUCT* data;
};

node_t* symtable_add(char* varName, struct IDENT_tokenData* data);
struct IDENT_tokenData* symtable_getItem(char* varName);
struct IDENT_tokenData* newID_token(int dataType, int init, INT_VAL value, char* varName, int var, struct DATA_STRUCT* data);
int symtable_removeItem(char* varName);

int symtable_removeItem__test(char* varName);
