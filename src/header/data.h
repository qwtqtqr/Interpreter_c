#ifndef extern_
#define extern_ 
#include <stdio.h>
#include "list.h"
struct STACK_FRAME
{
	struct STACK_FRAME* next;
	struct STACK_FRAME* prev;
	void* data;
};

struct VAR_STACK
{
	struct STACK_FRAME* head;
	struct STACK_FRAME* last;
};

#define TEXTLEN 512  
#define STRINGBUFF_LEN 512
extern char Text[TEXTLEN + 1];
extern int Line;
extern int Putback;
extern FILE* Infile;
extern FILE* Outfile;

extern unsigned int globl_open_curly_count;
extern unsigned int globl_closed_curly_count;
extern int globl_current_depth;
extern struct VAR_STACK* globl_var_stack;
extern int var_stack_size;

#endif
