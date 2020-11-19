#include "header/ast.h"
#include "header/data.h"
#include "header/scan.h"
#include "header/tokens.h"
#include "header/list.h"
#include "header/symtable.h"
#include <math.h>
#define PAREN_PRECEDENCE 20
#define BINEXPR_PTP_STARTVAL 0
#define INTERRUPT_TOKEN_DEFAULT -1


static double math_root(double x, double y)
{
	return (pow(x, 1 / y));
}

static int binOperators[] = { TT_PLUS, TT_MINUS, TT_MUL, TT_DIV, TT_OP_END, TT_EOF, TT_POW , TT_EQUALS_CMP, TT_NOT_EQUALS, TT_GREATER, TT_SMALLER, TT_GREATER_EQUALS, TT_SMALLER_EQUALS, TT_AND, TT_OR };

static int leftParenCount = 0;
static int rightParenCount = 0;

static int globl_inParen = 0;
static int globl_parenDelta = 0;

static int mainAST_init = 1;

static int curly_open_count = 0;
static int curly_closed_count = 0;


static void leftParenCode(struct Token* minusToken)
{
	while (currentToken->tokenType == TT_LEFT_PAREN)
	{
		leftParenCount++;
		if (minusToken->tokenType == TT_MINUS)
		{
			printf("[SYNTAX ERROR] Line %d\n", Line);
			exit(1);
		}
		scan_curToken();
		if (currentToken->tokenType == TT_EOF || currentToken->tokenType == TT_OP_END)
		{
			printf("[SYNTAX ERROR] unclosed parentheses in Line %d\n", Line);
			exit(1);
		}
		if (tokenIsBinOp(currentToken))
		{
			printf("[SYNATX ERROR] expected a number (Line %d) (Token %d)\n", Line, currentToken->tokenType);
			exit(1);
		}
	}
}


static int rightParenCode(int interrupt_token)
{
	while (currentToken->tokenType == TT_RIGHT_PAREN)
	{
		if (interrupt_token != -1)
		{
			if (currentToken->tokenType == TT_RIGHT_PAREN)
			{
				scan_curToken();
				if (currentToken->tokenType == interrupt_token)
				{
					rightParenCount = 0;
					leftParenCount = 0;
					return 1;
				}
				putBack_curToken(currentToken);
			}
		}
		rightParenCount++;
		scan_curToken();
	}

	if (leftParenCount != rightParenCount)
	{
		globl_inParen = PAREN_PRECEDENCE;
		globl_parenDelta = leftParenCount - rightParenCount;
	}

	if (leftParenCount == rightParenCount)
	{
		globl_inParen = 0;
		leftParenCount = 0;
		rightParenCount = 0;
		globl_parenDelta = 0;
	}

	if (currentToken->tokenType == TT_OP_END && leftParenCount != rightParenCount)
	{
		printf("[SYNTAX ERROR] unclosed parentheses in Line %d\n", Line);
		exit(1);
	}
	if (currentToken->tokenType == TT_INT || currentToken->tokenType == TT_FLOAT)
	{
		printf("[SYNTAX ERROR] expected a binary operator in Line %d\n", Line);
		exit(1);
	}
	return 0;
}

static int getParenPrecendece(struct Token* t)
{
	if (t->tokenType == TT_LEFT_PAREN)
	{
		leftParenCount++;
	}
	if (t->tokenType == TT_RIGHT_PAREN)
	{
		rightParenCount++;
	}

	if (rightParenCount != 0 && leftParenCount == rightParenCount)
	{
		leftParenCount = 0;
		rightParenCount = 0;
	}
	return 0;
}

static int getOpPrecedence(struct Token* t)
{
	int tt = t->tokenType;

	switch (tt)
	{
	case TT_INT:
		return 0;

	case TT_FLOAT:
		return 0;

	case TT_PLUS:
		return 10;

	case TT_MINUS:
		return 10;

	case TT_MUL:
		return 20;

	case TT_DIV:
		return 20;

	case TT_OP_END:
		return 0;

	case TT_POW:
		return 25;

	case TT_EQUALS_CMP:
		return 5;

	case TT_NOT_EQUALS:
		return 5;

	case TT_GREATER:
		return 5;

	case TT_SMALLER:
		return 5;

	case TT_GREATER_EQUALS:
		return 5;

	case TT_SMALLER_EQUALS:
		return 5;

	case TT_AND: return 2;

	case TT_OR: return 2;

	}
	return -1;
}

static int tokenIsBinOp(struct Token* t)
{
	for (size_t i = 0; i < arraySize(binOperators); i++)
	{
		if (t->tokenType == binOperators[i])
		{
			return 1;
		}
	}
	return 0;
}

struct AST_Node* mkastnode(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, struct AST_Node* right, void* otherData, struct DATA_STRUCT* data)
{
	struct AST_Node* initNode = malloc(sizeof(struct AST_Node));
	initNode->tokenType = tokenType;
	initNode->intVal = intVal;
	initNode->floatVal = floatVal;
	initNode->left = left;
	initNode->right = right;
	initNode->otherData = otherData;
	initNode->varName = NULL;
	initNode->data = data;
	return initNode;
}


struct AST_Node* mkastnode_const(int tokenType, INT_VAL intVal, double floatVal, void* otherData, struct DATA_STRUCT* data)
{
	return(mkastnode(tokenType, intVal, floatVal, NULL, NULL, otherData, data));
}

struct AST_Node* mkastnode_left(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, void* otherData, struct DATA_STRUCT* data)
{
	return(mkastnode(tokenType, intVal, floatVal, left, NULL, otherData, data));

}

struct AST_Node* mkastnode_ident(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, struct AST_Node* right, void* otherData, const char* varName, struct DATA_STRUCT* data)
{
	struct AST_Node* initNode = malloc(sizeof(struct AST_Node));
	initNode->tokenType = tokenType;
	initNode->intVal = intVal;
	initNode->floatVal = floatVal;
	initNode->left = left;
	initNode->right = right;
	initNode->otherData = otherData;
	initNode->varName = varName;
	initNode->data = data;
	return initNode;
}



struct AST_Node* binexpr_int(int ptp, int interrupt_token)
{
	int k = 0;
	struct  AST_Node* left, * right;
	scan_curToken(); // int or float
	int minusVal = 1;
	struct Token* minusToken = currentToken;
	while (currentToken->tokenType == TT_MINUS)
	{
		minusVal *= -1;
		scan_curToken();
	}
	leftParenCode(minusToken);

	if (currentToken->tokenType != TT_INT && currentToken->tokenType != TT_FLOAT && currentToken->tokenType != TT_IDENT && currentToken->tokenType != TT_BOOL_TRUE && currentToken->tokenType != TT_BOOL_FALSE)
	{
		printf("[SYNTAX ERROR] expected a number (Line %d)", Line);
		exit(1);
	}
	if (currentToken->data != NULL)
	{
		currentToken->data->minusVal = minusVal;
	}
	left = mkastnode_const(currentToken->tokenType, currentToken->intValue * minusVal, currentToken->floatVal * minusVal, NULL, currentToken->data);
	if (currentToken->tokenType == TT_IDENT)
	{
		char* saveIdentName = calloc(strlen(currentToken->IdentToken_name), sizeof(char));
		saveIdentName = strcpy(saveIdentName, currentToken->IdentToken_name);
		left = mkastnode_ident(TT_IDENT, minusVal, minusVal, NULL, NULL, newID_token(DT_INT, 1, 0, saveIdentName, 0, new_DATA_STRUCT(NULL, NULL, NULL, NULL, NULL, -1, minusVal)), saveIdentName, NULL);
	}
	if (currentToken->tokenType == TT_BOOL_TRUE)
	{
		int* boolVal = malloc(sizeof(int));
		*boolVal = 1;
		left = mkastnode(TT_BOOL_TRUE, 0, 0, NULL, NULL, NULL, new_DATA_STRUCT(NULL, boolVal, NULL, NULL, NULL, DT_BOOL, 1));
	}
	if (currentToken->tokenType == TT_BOOL_FALSE)
	{
		int* boolVal = malloc(sizeof(int));
		*boolVal = 0;
		left = mkastnode(TT_BOOL_FALSE, 0, 0, NULL, NULL, NULL, new_DATA_STRUCT(NULL, boolVal, NULL, NULL, NULL, DT_BOOL, 1));
	}
	minusVal = 1;
	int lastLine = Line;
	scan_curToken(); // bin operator

	

	if (rightParenCode(interrupt_token) == 1)
	{
		return left;
	}
	

	if (tokenIsBinOp(currentToken) == 0)
	{
		printf("[SYNTAX ERROR] expected a binary operator or ';' (Line %d)\n", lastLine);
		exit(1);
	}
	if (currentToken->tokenType == TT_EOF)
	{
		printf("[SYNTAX ERROR] expected a ';' in Line %d\n", lastLine);
		exit(1);
	}
	if (currentToken->tokenType == TT_OP_END)
	{
		if (interrupt_token == INTERRUPT_TOKEN_DEFAULT)
		{
			return left;
		}
		printf("[SYNTAX ERROR] cannot use ';' inside an expression (Line %d)\n", Line);
		exit(1);
	}

	while (getOpPrecedence(currentToken) + globl_inParen * globl_parenDelta > ptp)
	{
		struct Token* lastToken = currentToken;
		right = binexpr_int(getOpPrecedence(currentToken) + globl_inParen * globl_parenDelta, interrupt_token);
		left = mkastnode(lastToken->tokenType, lastToken->intValue, lastToken->floatVal, left, right, NULL, lastToken->data);
		if (lastToken->tokenType == TT_IDENT)
		{
			char* saveIdentName = calloc(strlen(lastToken->IdentToken_name), sizeof(char));
			saveIdentName = strcpy(saveIdentName, lastToken->IdentToken_name);
			left = mkastnode_ident(lastToken->tokenType, lastToken->intValue, lastToken->floatVal, left, right, newID_token(DT_INT, 1, 0, saveIdentName, 0, new_DATA_STRUCT(NULL, NULL, NULL, NULL, NULL, -1, minusVal)), saveIdentName, NULL);
		}
		if (lastToken->tokenType == TT_BOOL_TRUE)
		{
			left = mkastnode(TT_BOOL_TRUE, 0, 0, NULL, NULL, NULL, new_DATA_STRUCT(NULL, 1, NULL, NULL, NULL, DT_BOOL, 1));
		}
		if (lastToken->tokenType == TT_BOOL_FALSE)
		{
			left = mkastnode(TT_BOOL_FALSE, 0, 0, NULL, NULL, NULL, new_DATA_STRUCT(NULL, 0, NULL, NULL, NULL, DT_BOOL, 1));
		}

		rightParenCode(interrupt_token);
	}
	return left;
}



struct AST_Node* binexpr()
{
	struct AST_Node* left, * right, * node;
	scan_curToken();
	if (currentToken->tokenType != TT_INT && currentToken->tokenType != TT_FLOAT)
	{
		printf("[SYNTAX ERROR] expected a number (Line %d)", Line);
		exit(1);
	}
	left = mkastnode_const(currentToken->tokenType, currentToken->intValue, currentToken->floatVal, NULL, NULL);
	scan_curToken();
	if (tokenIsBinOp(currentToken) == 0)
	{
		printf("[SYNTAX ERROR] expected a binary operator (Line %d)\n", Line);
		exit(1);
	}
	struct Token* thisToken = currentToken;
	if (thisToken->tokenType == TT_OP_END)
	{
		return left;
	}
	if (currentToken->tokenType == TT_EOF)
	{
		printf("[SYNTAX ERROR] expected a ';' in Line %d\n", Line);
		exit(1);
	}
	right = binexpr();
	node = mkastnode(thisToken->tokenType, thisToken->intValue, thisToken->floatVal, left, right, NULL, NULL);
	return node;
}


struct AST_Node* genMainAST()
{
	struct AST_Node* left = NULL, * right = NULL, * node = NULL;
	scan_curToken();


	struct Token* t = currentToken;

	switch (currentToken->tokenType)
	{
	case TT_PRINT:

		scan_curToken();
		if (currentToken->tokenType != TT_LEFT_PAREN)
		{
			printf("[SYNTAX ERROR] '(' is missing in Line %d\n", Line);
			exit(1);
		}
		left = binexpr_int(BINEXPR_PTP_STARTVAL, TT_OP_END);
		node = mkastnode(t->tokenType, t->intValue, t->floatVal, left, NULL, NULL, NULL);
		break;

	case TT_VAR:
		node = genVarAST();
		node->right = genMainAST();
		return node;

	case TT_IDENT:
		node = genIdentAST();
		node->right = genMainAST();
		return node;

	case TT_UNDEF:
		scan_curToken();
		if (currentToken->tokenType != TT_IDENT)
		{
			printf("[SYNTAX ERROR] expected an identifier (Line %d)\n", Line);
			exit(1);
		}
		char* varName_save = calloc(strlen(currentToken->IdentToken_name), sizeof(char));
		varName_save = strcpy(varName_save, currentToken->IdentToken_name);
		left = mkastnode_ident(TT_IDENT, currentToken->intValue, currentToken->floatVal, NULL, NULL, NULL, varName_save, NULL);
		scan_curToken();
		if (currentToken->tokenType != TT_OP_END)
		{
			printf("[SYNTAX ERROR] expected a ';' in Line %d\n", Line);
			exit(1);
		}
		right = genMainAST();
		node = mkastnode(TT_UNDEF, 0, 0, left, right, NULL, NULL);
		return node;


	case TT_IF:
		scan_curToken();

		if (currentToken->tokenType != TT_LEFT_PAREN)
		{
			printf("[SYNTAX ERROR] '(' is missing in Line %d\n", Line);
			exit(1);
		}

		left = mkastnode(TT_ANY_OP, 0, 0, NULL, NULL, NULL, NULL);
		left->left = binexpr_int(0, TT_LEFT_CURLY);
		//left->right = genMainAST();   // if scope
		right = genMainAST();
		node = mkastnode(TT_IF, 0, 0, left, right, NULL, NULL);
		return node;

	}
	if (currentToken->tokenType == TT_EOF)
	{
		right = NULL;
	}
	else
	{
		right = genMainAST();
	}
	node = mkastnode(t->tokenType, t->intValue, t->floatVal, left, right, NULL, NULL);
	return node;
}









/*struct AST_Node* binexpr_p(int ptp)
{
	struct  AST_Node* left, * right;
	scan_curToken(); // int
	left = mkastnode_const(currentToken->tokenType, currentToken->intValue, currentToken->floatVal);
	scan_curToken(); // bin
	if (currentToken->tokenType == TT_OP_END)
	{
		return left;
	}
	while (getOpPrecendence(currentToken) > ptp)
	{
		struct Token* lastToken = currentToken;
		right = binexpr_p(getOpPrecendence(currentToken));
		left = mkastnode(lastToken->tokenType, lastToken->intValue, lastToken->floatVal, left, right);
	}
	return left;
}
*/