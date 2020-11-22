#ifndef extern_
#define extern_ 
#include <stdio.h>
#include "list.h"

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

#endif
