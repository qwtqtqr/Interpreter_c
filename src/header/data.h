#ifndef extern_
#define extern_ 
#include <stdio.h>

#define TEXTLEN 512  
#define STRINGBUFF_LEN 512
extern char Text[TEXTLEN + 1];
extern int Line;
extern int Putback;
extern FILE* Infile;
extern FILE* Outfile;
#endif
