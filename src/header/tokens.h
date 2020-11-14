#ifndef TOKENS_H
#define TOKENS_H

#define arraySize(x) sizeof(x)/sizeof(*x)
#define debugLog(x, y) printf(x, y)
#define INT_VAL  long long

#include "data.h"
#include "list.h"
#include <string.h>

extern struct Token* currentToken;

struct DATA_STRUCT
{
	char* strVal;
	int* boolVal;
	long double* doubleVal;
	long long* intVal;
	char* charVal;
	int dataType;
};


static struct DATA_STRUCT* new_DATA_STRUCT(char* strVal, int* boolVal, long double* doubleVal, long long intVal, char* charVal, int dataType)
{
	struct DATA_STRUCT* init = malloc(sizeof(struct DATA_STRUCT));
	init->strVal = strVal;
	init->boolVal = boolVal;
	init->doubleVal = doubleVal;
	init->intVal = intVal;
	init->charVal = charVal;
	init->dataType = dataType;
	return init;
};


static void free_DATA_STRUCT(struct DATA_STRUCT* data)
{
	free(data->strVal);
	free(data->boolVal);
	free(data->doubleVal);
	free(data->intVal);
	free(data->charVal);
	free(data);
}


static struct DATA_STRUCT* DATA_STRUCT_cpy(struct DATA_STRUCT* src)
{
	int* boolVal = NULL;
	if (src->boolVal != NULL)
	{
		boolVal = calloc(1, sizeof(int));
		*boolVal = *(src->boolVal);
	}
	int dt = src->dataType;
	char* strVal = NULL;
	if (src->strVal != NULL)
	{
		strVal = strcpy(strVal, src->strVal);
	}
	char* charVal = calloc(1, sizeof(char));
	if (src->charVal != NULL)
	{
		*charVal = *(src->charVal);
	}
	long double* doubleVal = NULL;
	if (src->doubleVal != NULL)
	{
		doubleVal = calloc(0, sizeof(long double));
		*doubleVal = *(src->doubleVal);
	}
	long long* intVal = NULL;
	if (src->intVal != NULL)
	{
		intVal = calloc(1, sizeof(long long));
		*intVal = *(src->intVal);
	}
	return new_DATA_STRUCT(strVal, boolVal, doubleVal, intVal, charVal, dt);
}


enum
{
	TT_PLUS,
	TT_MINUS,
	TT_MUL,
	TT_DIV,
	TT_POW,
	TT_INT,
	TT_OP_END,
	TT_PRINT,
	TT_IF,
	TT_LEFT_PAREN,
	TT_RIGHT_PAREN,
	TT_LEFT_CURLY,
	TT_RIGHT_CURLY,
	TT_STRING,
	TT_WHILE,
	TT_CHAR,
	TT_FLOAT,
	TT_EOF,
	TT_IDENT,
	TT_EQUALS,
	TT_VAR,
	TT_UNDEF,
	TT_EQUALS_CMP,
	TT_AND,
	TT_OR,
	TT_ANY_OP,
	TT_NOT_EQUALS,
	TT_GREATER,
	TT_SMALLER,
	TT_GREATER_EQUALS,
	TT_SMALLER_EQUALS,
};



enum
{
	DT_INT,
	DT_DOUBLE,
	DT_FLOAT,
	DT_CHAR,
	DT_STRING,
	DT_BOOL,
};


struct Token
{
	int tokenType;
	INT_VAL intValue;
	int line;
	char* strVal;
	double floatVal;

	char* IdentToken_name;
	INT_VAL IdentToken_data;
	struct DATA_STRUCT* data;
};




struct TokenIdent
{
	char* tokenStr;
	int tokenType;
};

static struct TokenIdent multicharTokens[] =
{
	{"print", TT_PRINT}, {"if", TT_IF},
	{"while", TT_WHILE}, {"var", TT_VAR},
	{"undef", TT_UNDEF},
};

struct NumericVal
{
	INT_VAL intVal;
	double floatVal;
	int tokenType;
};



static struct TokenIdent singleCharTokens[] =
{
	{'+', TT_PLUS}, {'-', TT_MINUS},
	{'*', TT_MUL}, {'/', TT_DIV},
	{'^', TT_POW}, {';', TT_OP_END},
	{'(', TT_LEFT_PAREN}, {')', TT_RIGHT_PAREN},
	{'{', TT_LEFT_CURLY}, {'}', TT_LEFT_CURLY},
	/*{'=', TT_EQUALS}, {'|', TT_OR}, 
	{'&', TT_AND},*/
};

static struct Token* newToken(int tokenType, INT_VAL intValue, int line, struct DATA_struct* data)
{
	struct Token* initToken = malloc(sizeof(struct Token));
	initToken->tokenType = tokenType;
	initToken->intValue = intValue;
	initToken->line = line;
	initToken->strVal = NULL;
	initToken->floatVal = 0;
	initToken->IdentToken_name = NULL;
	initToken->IdentToken_data = 0;
	initToken->data = data;
	return initToken;
}

static struct Token* newToken_str(int tokenType, INT_VAL intValue, int line, char* strVal, struct DATA_struct* data)
{
	struct Token* initToken_str = malloc(sizeof(struct Token));
	initToken_str->tokenType = tokenType;
	initToken_str->intValue = intValue;
	initToken_str->line = line;
	initToken_str->strVal = strVal;
	initToken_str->floatVal = 0;
	initToken_str->IdentToken_name = NULL;
	initToken_str->IdentToken_data = 0;
	initToken_str->data = data;
	return initToken_str;
}

static struct Token* newToken_float(int tokenType, double floatVal, int line, struct DATA_struct* data)
{
	struct Token* initToken_float = malloc(sizeof(struct Token));
	initToken_float->tokenType = tokenType;
	initToken_float->intValue = 0;
	initToken_float->line = line;
	initToken_float->strVal = NULL;
	initToken_float->floatVal = floatVal;
	initToken_float->IdentToken_name = NULL;
	initToken_float->IdentToken_data = 0;
	initToken_float->data = data;
	return initToken_float;
}

static struct Token* newToken_identToken(int tokenType, int line, char* identToken_name, INT_VAL identToken_data, struct DATA_struct* data)
{
	struct Token* initToken = malloc(sizeof(struct Token));
	initToken->tokenType = tokenType;
	initToken->intValue = 0;
	initToken->line = line;
	initToken->strVal = NULL;
	initToken->floatVal = 0;
	initToken->IdentToken_name = identToken_name;
	initToken->IdentToken_data = identToken_data;
	initToken->data = data;
	return initToken;
}


static void addToken(LinkedList* tokenList, int tokenType, INT_VAL intValue, int line)
{
	LinkedList_add_end(tokenList, newToken(tokenType, intValue, line, NULL), 0, 0, NULL);
}

#endif
