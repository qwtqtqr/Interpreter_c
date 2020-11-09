#include "header/symtable.h"
#include<string.h>


void symtable_add(char* varName, struct IDENT_tokenData* data)
{
	LinkedList_add_end(globl_symtable, data, 0, 0, varName);
}


struct IDENT_tokenData* symtable_getItem(char* varName)
{
	for (int i = 0; i < LinkedList_size(globl_symtable); i++)
	{
		struct IDENT_tokenData* curID =(struct IDENT_tokenData*) LinkedList_getItem(globl_symtable, i);
		char* curName = curID->varName;
		if (strcmp(varName, curName) == 0)
		{
			return curID;
		}

	}
	return NULL;
}


struct IDENT_tokenData* newID_token(int dataType, int init, INT_VAL value, char* varName)
{
	struct IDENT_tokenData* initID = malloc(sizeof(struct IDENT_tokenData));
	initID->dataType = dataType;
	initID->init = init;
	initID->value = value;
	initID->varName = varName;
	return initID;
}