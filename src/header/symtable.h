#include <stdio.h>
#include "tokens.h"
#include "list.h"

#pragma once


extern LinkedList* globl_symtable;


struct IDENT_tokenData
{
	char* varName;
	int dataType;
	int init;
	INT_VAL value;
};

void symtable_add(char* varName, struct IDENT_tokenData* data);
struct IDENT_tokenData* symtable_getItem(char* varName);
struct IDENT_tokenData* newID_token(int dataType, int init, INT_VAL value, char* varName);