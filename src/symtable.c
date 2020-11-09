#include "header/symtable.h"
#include "header/data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void symtable_add(const char* varName, struct tableNode* data)
{
	LinkedList_add(globl_symtable, LinkedList_size(globl_symtable), data, 0, 0, varName);
}


struct tableNode* symtable_getItem(const char* varName)
{
	node_t* curNode = globl_symtable->head;
	while (curNode != NULL)
	{
		struct tableNode* tNode =(struct tableNode*) curNode->data;
		const char* varName_tNode = curNode->varName;
		if (strcmp(varName, varName_tNode) == 0)
		{
			//printf("right node::  %s\n", varName_tNode);
			return tNode;
		}
		curNode = curNode->next;
	}
	return NULL;
}


struct tableNode* newTableNode(const char* varName, int dataType, INT_VAL value, int hasValue)
{
	struct tableNode* initNode = malloc(sizeof(struct tableNode));
	initNode->dataType = dataType;
	initNode->hash = 0;
	initNode->hasValue = hasValue;
	initNode->value = value;
	initNode->varName = varName;
	return initNode;
}