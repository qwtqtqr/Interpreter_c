#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "list.h"

#ifndef SCAN_H
#define SCAN_H

int next(void);
void putback(int c);
int skip(void);
void scan_tokens(LinkedList* tokenList, struct Token* t);
int chrpos(char* s, int c);
struct NumericVal scanIntAndFloat(int c);
int scanident(int c, char* buf, int lim);
//int keyword(char* s);
char* createFinalString(LinkedList* strBufferList);
void createNewString(int c, LinkedList* buffList);
char scanChars(int c);
void scan_curToken();
void skip_comments(int c_);

#endif
