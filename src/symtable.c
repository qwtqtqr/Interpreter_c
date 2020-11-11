#include "header/symtable.h"
#include<string.h>


static unsigned long long hash_string(const char* s)
{
    unsigned long long hash = 0;

    for (; *s; ++s)
    {
        hash += *s;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

unsigned int getBucketVal(unsigned long long hash)
{
    return (unsigned int)(hash % SYMTABLE_SIZE);
}

void symtable_add(char* varName, struct IDENT_tokenData* data)
{
    unsigned long long hash = hash_string(varName);
    unsigned int bucket = getBucketVal(hash);
    
    if (globl_symtable[bucket] == NULL)
    {  
        globl_symtable[bucket] = newLinkedList();
    }
    LinkedList_add_end(globl_symtable[bucket], data, 0, NULL, varName);
}


struct IDENT_tokenData* symtable_getItem(char* varName)
{
    unsigned long long hash = hash_string(varName);
    unsigned int bucket = getBucketVal(hash);

    if (globl_symtable[bucket] == NULL)
    {
        return NULL;
    }
    node_t* curNode_head = globl_symtable[bucket]->head;
    node_t* curNode_tail = globl_symtable[bucket]->tail;

    while (curNode_head != NULL && curNode_tail != NULL)
    {
        char* varName_head = curNode_head->varName;
        if (strcmp(varName, varName_head) == 0)
        {
            return (struct IDENT_tokenData*) curNode_head->data;
        }
        char* varName_tail = curNode_tail->varName;
        if (strcmp(varName, varName_tail) == 0)
        {
            return (struct IDENT_tokenData*)curNode_tail->data;
        }
        curNode_head = curNode_head->next;
        curNode_tail = curNode_tail->last;
    }
    return NULL;
}

void symtable_setItemVal(char* varName, INT_VAL value)
{
    unsigned long long hash = hash_string(varName);
    unsigned int bucket = getBucketVal(hash);

    if (globl_symtable[bucket] == NULL)
    {
        return;
    }
    node_t* curNode_head = globl_symtable[bucket]->head;
    node_t* curNode_tail = globl_symtable[bucket]->tail;

    while (curNode_head != NULL && curNode_tail != NULL)
    {
        char* varName_head = curNode_head->varName;
        if (strcmp(varName, varName_head) == 0)
        {
            struct IDENT_tokenData* curID = (struct IDENT_tokenData*)curNode_head->data;
            curID->value = value;
            return;
        }
        char* varName_tail = curNode_tail->varName;
        if (strcmp(varName, varName_tail) == 0)
        {
            struct IDENT_tokenData* curID = (struct IDENT_tokenData*)curNode_head->data;
            curID->value = value;
            return;
        }
        curNode_head = curNode_head->next;
        curNode_tail = curNode_tail->last;
    }
}


struct IDENT_tokenData* newID_token(int dataType, int init, INT_VAL value, char* varName, int var, struct DATA_STRUCT* data)
{
    struct IDENT_tokenData* initID = malloc(sizeof(struct IDENT_tokenData));
    initID->dataType = dataType;
    initID->init = init;
    initID->value = value;
    initID->varName = varName;
    initID->var = var;
    initID->data = data;
    return initID;
}