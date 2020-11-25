#include <stdio.h>
#include "header/ast.h"
#include "header/symtable.h"
#include "header/tokens.h"
#include "header/data.h"
#include "header/list.h"

struct STACK_FRAME* mkframe(void* data)
{
	struct STACK_FRAME* init = malloc(sizeof(struct STACK_FRAME));
	init->data = data;
	init->next = NULL;
	return init;
}

struct VAR_STACK* mkVarStack()
{
	struct VAR_STACK* init = malloc(sizeof(struct VAR_STACK));
	init->head = NULL;
	init->last = NULL;
	return init;
}


void varStack_add(struct VAR_STACK* varStack, void* data)
{
	if (varStack == NULL)
	{
		varStack = mkVarStack();

	}
	struct STACK_FRAME* node = mkframe(data);

	struct STACK_FRAME* curNode = varStack->head;

	if (curNode == NULL)
	{
		varStack->head = node;
		//curNode = node;
		varStack->last = node;
		return;
	}

	while (curNode->next != NULL)
	{
		curNode = curNode->next;
	}
	curNode->next = node;
	varStack->last = node;

}


void varStack_remove(struct VAR_STACK* varStack)
{
	struct STACK_FRAME* curNode = varStack->head;
	if (curNode == NULL)
	{
		return;
	}
	if (curNode->next == NULL)
	{
		curNode = NULL;
		return;
	}

	while (curNode->next->next != NULL)
	{
		curNode = curNode->next;
	}
	curNode = NULL;
}


void varStack_push_frame()
{
	varStack_add(globl_var_stack, mkVarStack());
	var_stack_size++;
}

struct VAR_STACK* varStack_getFrame()
{
	struct STACK_FRAME* curNode = globl_var_stack->head;
	while (curNode->next != NULL)
	{

		curNode = curNode->next;
	}
	return curNode->data;
}


void stackFrame_add_var(char* varName)
{
	varStack_add(varStack_getFrame(), varName);
}


void varStack_pop_frame()
{
	struct VAR_STACK* curSTACK = varStack_getFrame();
	struct STACK_FRAME* curNode = curSTACK->head;

	while (curNode != NULL)
	{
		char* curVarName = (char*)curNode->data;
		symtable_removeItem__test(curVarName);
		curNode = curNode->next;
	}
	varStack_remove(curSTACK);
	var_stack_size--;
}