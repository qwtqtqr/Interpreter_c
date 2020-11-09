#include "list.h"
#include "tokens.h"
#ifndef TABLE_H
#define TABLE_H

#define SYMTABLE_SIZE 16

extern LinkedList* globl_symtable;

struct tableNode
{
	char* varName;
	unsigned long long hash;
	int dataType;
	INT_VAL value;
	int hasValue;
};

enum
{
	DT_INT,
	DT_DOUBLE,
	DT_STRING,
	DT_CHAR,
	DT_BOOL,
};



unsigned long long hash_str(const char* s);
int cmp_string(const char* s1, const char* s2);

void symtable_add(const char* varName, struct tableNode* data);
void symtable_remove(const char* varName);
struct tableNode* symtable_getItem(const char* varName);

struct tableNode* newTableNode(const char* varName, int dataType, INT_VAL value, int hasValue);

void sym_init();


#endif