#ifndef TOKENS_H
#define TOKENS_H

#define arraySize(x) sizeof(x)/sizeof(*x)
#define debugLog(x, y) printf(x, y)
#define INT_VAL  long long



#include "data.h"
#include "list.h"


extern struct Token* currentToken;

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
	{'=', TT_EQUALS}
};

static struct Token* newToken(int tokenType, INT_VAL intValue, int line)
{
	struct Token* initToken = malloc(sizeof(struct Token));
	initToken->tokenType = tokenType;
	initToken->intValue = intValue;
	initToken->line = line;
	initToken->strVal = NULL;
	initToken->floatVal = 0;
	initToken->IdentToken_name = NULL;
	initToken->IdentToken_data = 0;
	return initToken;
}

static struct Token* newToken_str(int tokenType, INT_VAL intValue, int line, char* strVal)
{
	struct Token* initToken_str = malloc(sizeof(struct Token));
	initToken_str->tokenType = tokenType;
	initToken_str->intValue = intValue;
	initToken_str->line = line;
	initToken_str->strVal = strVal;
	initToken_str->floatVal = 0;
	initToken_str->IdentToken_name = NULL;
	initToken_str->IdentToken_data = 0;
	return initToken_str;
}

static struct Token* newToken_float(int tokenType, double floatVal, int line)
{
	struct Token* initToken_float = malloc(sizeof(struct Token));
	initToken_float->tokenType = tokenType;
	initToken_float->intValue = 0;
	initToken_float->line = line;
	initToken_float->strVal = NULL;
	initToken_float->floatVal = floatVal;
	initToken_float->IdentToken_name = NULL;
	initToken_float->IdentToken_data = 0;
	return initToken_float;
}

static struct Token* newToken_identToken(int tokenType, int line, char* identToken_name, INT_VAL identToken_data)
{
	struct Token* initToken = malloc(sizeof(struct Token));
	initToken->tokenType = tokenType;
	initToken->intValue = 0;
	initToken->line = line;
	initToken->strVal = NULL;
	initToken->floatVal = 0;
	initToken->IdentToken_name = identToken_name;
	initToken->IdentToken_data = identToken_data;
}


static void addToken(LinkedList* tokenList, int tokenType, INT_VAL intValue, int line)
{
	LinkedList_add_end(tokenList, newToken(tokenType, intValue, line), 0, 0, NULL);
}

#endif
