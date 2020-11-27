#include "header/scan.h"
#include "header/data.h"
#include <math.h>
#include <time.h>
#include "header/symtable.h"
#include "header/tokens.h"


// Scan an identifier from the input file and
// store it in buf[]. Return the identifier's length
int scanident(int c, char* buf, int lim) {
	int i = 0;

	// Allow digits, alpha and underscores
	while (isalpha(c) || isdigit(c) || '_' == c) {
		// Error if we hit the identifier length limit,
		// else append to buf[] and get next character
		if (lim - 1 == i) {
			printf("identifier too long line %d\n", Line);
			exit(1);
		}
		else if (i < lim - 1) {
			buf[i++] = c;
		}
		c = next();
	}
	// We hit a non-valid character, put it back.
	// NUL-terminate the buf[] and return the length
	putback(c);
	buf[i] = '\0';
	return (i);
}

static struct keyword_returnVal
{
	int TokenType;

	char* ident_name;
};


struct keyword_returnVal keyword(char* s) {
	for (size_t i = 0; i < arraySize(multicharTokens); i++)
	{
		struct TokenIdent curToken = multicharTokens[i];

		if (!strcmp(s, curToken.tokenStr))
		{
			struct keyword_returnVal retVal = { curToken.tokenType, NULL };
			return (retVal);
		}
	}
	struct keyword_returnVal retVal_ident = { TT_IDENT, s };
	return retVal_ident;
}


void createNewString(int c, LinkedList* buffList)
{
	int strStartLine = Line;
	c = next();
	int curStrBuffIdx = 0;
	char* buff = calloc(STRINGBUFF_LEN, sizeof(char));
	int bufferCount = 1;


	while (c != '"' && c != EOF)
	{
		buff[curStrBuffIdx] = c;
		c = next();
		curStrBuffIdx++;
		if (curStrBuffIdx == STRINGBUFF_LEN)
		{
			LinkedList_add_end(buffList, (char*)buff, 0, 0, NULL);
			buff = calloc(STRINGBUFF_LEN, sizeof(char));
			curStrBuffIdx = 0;
			bufferCount++;
		}
	}
	LinkedList_add_end(buffList, (char*)buff, 0, 0, NULL);
	if (c == EOF)
	{
		printf("[SYNTAX ERROR]  a '%c' is missing (Line %d)\n ", '"', strStartLine);
		exit(1);
	}
}

char* createFinalString(LinkedList* strBufferList)
{
	size_t size = (size_t)LinkedList_size(strBufferList) * STRINGBUFF_LEN + 1;
	char* returnString = calloc(size, sizeof(char));

	int curIdx = 0;

	node_t* listNode = LinkedList_getNode(strBufferList, 0);
	while (listNode != NULL)
	{
		char* curBuffer = (char*)listNode->data;
		for (int c = 0; c < STRINGBUFF_LEN; c++)
		{
			char curChar = *(curBuffer + c);
			returnString[curIdx] = curChar;
			if (c < STRINGBUFF_LEN - 1)
			{
				if (curChar == '\0')
				{
					return returnString;
				}
			}
			curIdx++;
		}
		listNode = listNode->next;
	}
	returnString[curIdx + 1] = '\0';
	return returnString;
}



static int scan_cmp_operators(int c_)
{
	int c = c_;
	switch (c)
	{
	case '=':
		c = next();
		if (c == '=')
		{
			return TT_EQUALS_CMP;
		}

		putback(c);
		return TT_EQUALS;

	case '!':
		c = next();
		if (c == '=')
		{
			return TT_NOT_EQUALS;
		}
		printf("[ERROR] unknown token in Line %d\n", Line);
		exit(1);

	case '>':
		c = next();
		if (c == '=')
		{
			return TT_GREATER_EQUALS;
		}
		putback(c);
		return TT_GREATER;

	case '<':
		c = next();
		if (c == '=')
		{
			return TT_SMALLER_EQUALS;
		}
		putback(c);
		return TT_SMALLER;

	case '&':
		c = next();
		if (c == '&')
		{
			return TT_AND;
		}
		printf("[ERROR] unknown token in Line %d\n", Line);
		exit(1);

	case '|':
		c = next();
		if (c == '|')
		{
			return TT_OR;
		}
		printf("[ERROR] unknown token in Line %d\n", Line);
		exit(1);

	}
	return -1;
}

void putBack_curToken(struct Token* token)
{
	globl_putback_token = token;
}



int next(void)
{
	int c;

	if (Putback)
	{
		c = Putback;
		Putback = 0;
		return c;
	}

	c = fgetc(Infile);
	if ('\n' == c)
		Line++;
	return c;
}

void putback(int c)
{
	Putback = c;
}

int skip(void)
{
	int c;

	c = next();
	while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c)
	{
		c = next();
	}
	return c;
}


int chrpos(char* s, int c)
{
	char* p;

	p = strchr(s, c);
	return (p ? p - s : -1);
}


struct NumericVal scanIntAndFloat(int c)   // integer and double
{
	INT_VAL val = 0;
	INT_VAL k;

	int isFloat = 0;
	int count = 0;
	int dotPos = -1;
	int firstNum = 9;
	while ((k = chrpos("0123456789", c)) >= 0 || c == '.') {
		if (count == 0)
		{
			firstNum = (int)k;
		}
		count++;
		if (c == '.')
		{
			isFloat = 1;
			dotPos = count;
		}
		if (c != '.')
		{
			val = val * 10 + k;
		}
		c = next();
	}
	putback(c);

	if (isFloat)
	{

		if (count >= 19)
		{
			/*intf("[STACK ERROR] number has to many digits  (Line %d)\n", Line);
			exit(1);*/
		}
		INT_VAL divNum = (INT_VAL)pow(10, ((double)count - dotPos));
		double floatVal = (double)val / (double)divNum;
		struct NumericVal floatStruct = { 0, floatVal, TT_FLOAT };
		return floatStruct;
	}

	if (count >= 10 && firstNum > 1)
	{
		/*printf("[STACK ERROR] number has to many digits  (Line %d)\n", Line);
		exit(1)*/
	}


	struct NumericVal intStruct = { val, 0, TT_INT };
	return intStruct;
}



char scanChars(int c)
{
	c = next();
	next();
	return c;
}


void scan_tokens(LinkedList* tokenList, struct Token* t)
{
	int c = 0;

	while (c != EOF)
	{
		//scan_curToken(tokenList, t, c);
	}
}

int skip_comments(int c_)
{
	int c = c_;
	if (c == '/')
	{
		c = next();
		if (c == '/')
		{
			while (c != '\n' && c != EOF)
			{
				c = next();
			}
		}
		else {
			putback(c);
			return -1;
		}
	}
	return 1;
}


void printToken(int tokenType)
{
	switch (tokenType)
	{
	case TT_PLUS:              printf("TT_PLUS\n"); break;
	case TT_MINUS:             printf("TT_MINUS\n"); break;
	case TT_MUL:               printf("TT_MUL\n"); break;
	case TT_DIV:               printf("TT_DIV\n"); break;
	case TT_POW:               printf("TT_POW\n"); break;
	case TT_INT:               printf("TT_INT\n"); break;
	case TT_OP_END:            printf("TT_OP_END\n"); break;
	case TT_PRINT:             printf("TT_PRINT\n"); break;
	case TT_IF:                printf("TT_IF\n"); break;
	case TT_LEFT_PAREN:        printf("TT_LEFT_PAREN\n"); break;
	case TT_RIGHT_PAREN:       printf("TT_RIGHT_PAREN\n"); break;
	case TT_LEFT_CURLY:        printf("TT_LEFT_CURLY\n"); break;
	case TT_RIGHT_CURLY:       printf("TT_RIGHT_CURLY\n"); break;
	case TT_STRING:            printf("TT_STRING\n"); break;
	case TT_WHILE:             printf("TT_WHILE\n"); break;
	case TT_CHAR:              printf("TT_CHAR\n"); break;
	case TT_FLOAT:             printf("TT_FLOAT\n"); break;
	case TT_EOF:               printf("TT_EOF\n"); break;
	case TT_IDENT:             printf("TT_IDENT\n"); break; 
	case TT_EQUALS:            printf("TT_EQUALS\n"); break;
	case TT_VAR:               printf("TT_VAR\n"); break;
	case TT_UNDEF:             printf("TT_UNDEF\n"); break;
	case TT_EQUALS_CMP:        printf("TT_EQUALS_CMP\n"); break;
	case TT_AND:               printf("TT_AND\n"); break;
	case TT_OR:                printf("TT_OR\n"); break;
	case TT_ANY_OP:            printf("TT_ANY_OP\n"); break;
	case TT_GREATER:           printf("TT_GREATER\n"); break;
	case TT_SMALLER:           printf("TT_SMALLER\n"); break;
	case TT_GREATER_EQUALS:    printf("TT_GREATER_EQUALS\n"); break;
	case TT_SMALLER_EQUALS:    printf("TT_SMALLER_EQUALS\n"); break;
	case TT_BOOL_TRUE:         printf("TT_BOOL_TRUE\n"); break;
	case TT_BOOL_FALSE:        printf("TT_BOOL_FALSE\n"); break;
	case TT_SCOPE:             printf("TT_SCOPE\n"); break;
	case TT_SCOPE_END:         printf("TT_SCOPE_END\n"); break;
	}
}




void scan_curToken()
{

	if (globl_putback_token != NULL)
	{
		currentToken = globl_putback_token;
		globl_putback_token = NULL;
		return;
	}

	int c = skip();
	int x = skip_comments(c);
	if (x == -1)
	{
		currentToken = newToken(TT_DIV, 0, 0, Line, NULL);
		return;
	}

	if (c == EOF)
	{
		currentToken = newToken(TT_EOF, 0, Line, NULL);
	}
	for (size_t i = 0; i < arraySize(singleCharTokens); i++)
	{
		struct TokenIdent curIdent = singleCharTokens[i];
		if (curIdent.tokenStr == c)
		{
			currentToken = newToken(curIdent.tokenType, 0, Line, NULL);
			putback(' ');
			return;
		}
	}

	int cmp_op = scan_cmp_operators(c);
	if (cmp_op != -1)
	{
		currentToken = newToken(cmp_op, 0, Line, NULL);
		return;

	}

	if (isdigit(c))
	{
		struct NumericVal numStruct = scanIntAndFloat(c);
		int numTT = numStruct.tokenType;

		if (numTT == TT_INT)
		{
			INT_VAL intVal = numStruct.intVal;
			long long* intValPtr = malloc(sizeof(long long));
			*intValPtr = intVal;

			currentToken = newToken(TT_INT, intVal, Line, new_DATA_STRUCT(NULL, NULL, NULL, intValPtr, NULL, DT_INT, 1));
		}
		if (numTT == TT_FLOAT)
		{
			double floatVal = numStruct.floatVal;
			long double* floatValPtr = malloc(sizeof(long double));
			*floatValPtr = floatVal;
			currentToken = newToken_float(TT_FLOAT, floatVal, Line, new_DATA_STRUCT(NULL, NULL, floatValPtr, NULL, NULL, DT_FLOAT, 1));
		}
	}

	else if (isalpha(c) || c == '_')
	{

		scanident(c, Text, TEXTLEN);
		struct keyword_returnVal cur_key_ret_val = keyword(Text);
		int keyword_tt = cur_key_ret_val.TokenType;
		if (keyword_tt != TT_IDENT)
		{
			currentToken = newToken(keyword_tt, 0, Line, NULL);
		}
		if (keyword_tt == TT_IDENT)
		{
			currentToken = newToken_identToken(TT_IDENT, Line, cur_key_ret_val.ident_name, 0, NULL);
		}
	}

	if (c == '"')
	{
		LinkedList* strList = newLinkedList();
		createNewString(c, strList);
		char* string_final = createFinalString(strList);
		currentToken = newToken_str(TT_STRING, 0, Line, string_final, new_DATA_STRUCT(string_final, NULL, NULL, NULL, NULL, DT_STRING, 1));

		free(strList);
	}

	char charT[] = "'";
	if (c == charT[0])
	{
		char val = scanChars(c);
		char* valPtr = malloc(sizeof(char));
		*valPtr = val;
		currentToken = newToken_str(TT_CHAR, 0, Line, val, new_DATA_STRUCT(NULL, NULL, NULL, NULL, valPtr, DT_CHAR, 1));
	}
}
