#include "header/ast.h"
#include "header/data.h"
#include "header/scan.h"
#include "header/tokens.h"
#include "header/list.h"
#include "header/symtable.h"
#include <math.h>


static double math_root(double x, double y)
{
	return (pow(x, 1 / y));
}

#define PAREN_PRECEDENCE 20

static int binOperators[] = { TT_PLUS, TT_MINUS, TT_MUL, TT_DIV, TT_OP_END, TT_EOF, TT_POW };

static int leftParenCount = 0;
static int rightParenCount = 0;

static int globl_inParen = 0;
static int globl_parenDelta = 0;

static int mainAST_init = 1;

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


static void rightParenCode()
{
	while (currentToken->tokenType == TT_RIGHT_PAREN)
	{
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

struct AST_Node* mkastnode(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, struct AST_Node* right, void* otherData)
{
	struct AST_Node* initNode = malloc(sizeof(struct AST_Node));
	initNode->tokenType = tokenType;
	initNode->intVal = intVal;
	initNode->floatVal = floatVal;
	initNode->left = left;
	initNode->right = right;
	initNode->otherData = otherData;
	initNode->varName = NULL;
	return initNode;
}


struct AST_Node* mkastnode_const(int tokenType, INT_VAL intVal, double floatVal, void* otherData)
{
	return(mkastnode(tokenType, intVal, floatVal, NULL, NULL, otherData));
}

struct AST_Node* mkastnode_left(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, void* otherData)
{
	return(mkastnode(tokenType, intVal, floatVal, left, NULL, otherData));

}

struct AST_Node* mkastnode_ident(int tokenType, INT_VAL intVal, double floatVal, struct AST_Node* left, struct AST_Node* right, void* otherData, const char* varName)
{
	struct AST_Node* initNode = malloc(sizeof(struct AST_Node));
	initNode->tokenType = tokenType;
	initNode->intVal = intVal;
	initNode->floatVal = floatVal;
	initNode->left = left;
	initNode->right = right;
	initNode->otherData = otherData;
	initNode->varName = varName;
	return initNode;
}



struct AST_Node* binexpr_int(int ptp)
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

	if (currentToken->tokenType != TT_INT && currentToken->tokenType != TT_FLOAT && currentToken->tokenType != TT_IDENT)
	{
		printf("[SYNTAX ERROR] expected a number (Line %d)", Line);
		exit(1);
	}

	left = mkastnode_const(currentToken->tokenType, currentToken->intValue * minusVal, currentToken->floatVal * minusVal, NULL);
	if (currentToken->tokenType == TT_IDENT)
	{
		char* saveIdentName = calloc(strlen(currentToken->IdentToken_name), sizeof(char));
		saveIdentName = strcpy(saveIdentName, currentToken->IdentToken_name);
		left = mkastnode_ident(TT_IDENT, minusVal, minusVal, NULL, NULL, newID_token(DT_INT, 1, 0, saveIdentName, 0), saveIdentName);
	}
	minusVal = 1;
	int lastLine = Line;
	scan_curToken(); // bin operator

	rightParenCode();

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
		return left;
	}
	while (getOpPrecedence(currentToken) + globl_inParen * globl_parenDelta > ptp)
	{
		struct Token* lastToken = currentToken;
		right = binexpr_int(getOpPrecedence(currentToken) + globl_inParen * globl_parenDelta);
		left = mkastnode(lastToken->tokenType, lastToken->intValue, lastToken->floatVal, left, right, NULL);
		if (lastToken->tokenType == TT_IDENT)
		{
			char* saveIdentName = calloc(strlen(lastToken->IdentToken_name), sizeof(char));
			saveIdentName = strcpy(saveIdentName, lastToken->IdentToken_name);
			left = mkastnode_ident(lastToken->tokenType, lastToken->intValue, lastToken->floatVal, left, right, newID_token(DT_INT, 1, 0, saveIdentName, 0), saveIdentName);
		}

		rightParenCode();
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
	left = mkastnode_const(currentToken->tokenType, currentToken->intValue, currentToken->floatVal, NULL);
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
	node = mkastnode(thisToken->tokenType, thisToken->intValue, thisToken->floatVal, left, right, NULL);
	return node;
}


INT_VAL interpretAST_int(struct AST_Node* root)
{
	int leftVal, rightVal;
	struct IDENT_tokenData* curIdent = NULL;
	struct tableNode* tNode = NULL;

	if (root->left != NULL)
	{
		leftVal = interpretAST_int(root->left);
	}
	if (root->right != NULL) {
		rightVal = interpretAST_int(root->right);
	}
	switch (root->tokenType)
	{
	case TT_PLUS:
		return (leftVal + rightVal);

	case TT_MINUS:
		return (leftVal - rightVal);

	case TT_MUL:
		return (leftVal * rightVal);

	case TT_DIV:
		if (rightVal == 0)
		{
			printf("[ERROR] division by zero error!");
			exit(1);
		}
		return (leftVal / rightVal);

	case TT_POW:
		return ((INT_VAL)pow((double)leftVal, (double)rightVal));

	case TT_INT:
		return root->intVal;

	case TT_IDENT:
		curIdent = (struct IDENT_tokenData*)symtable_getItem(root->varName);
		if (curIdent == NULL)
		{
			printf("[ERROR] variable does not exist\n");
			exit(1);
		}
		return curIdent->value * root->intVal;

	}
}


struct AST_Node* genMainAST()
{
	struct AST_Node* left = NULL, * right = NULL, * node = NULL;
	scan_curToken();
	struct Token* t = currentToken;

	switch (currentToken->tokenType)
	{
	case TT_PRINT:
		left = binexpr_int(0);
		node = mkastnode(t->tokenType, t->intValue, t->floatVal, left, NULL, NULL);
		break;

	case TT_VAR:
		node = genVarAST();
		node->right = genMainAST();
		return node;

	case TT_IDENT:
		node = genIdentAST();
		node->right = genMainAST();
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
	node = mkastnode(t->tokenType, t->intValue, t->floatVal, left, right, NULL);
	return node;
}




void interpretMainAST(struct AST_Node* root)
{
	struct AST_Node* curNode = root;
	while (curNode != NULL)
	{
		if (curNode->tokenType == TT_PRINT)
		{
			INT_VAL printVal = interpretAST_int(curNode->left);
			printf("%lld\n", printVal);
		}

	        else if (curNode->tokenType == TT_IDENT)
		    {
			    struct IDENT_tokenData* curNodeData = (struct IDENT_tokenData*)curNode->otherData;
			    char* saveVarName = calloc(strlen(curNode->varName), sizeof(char));
			    saveVarName = strcpy(saveVarName, curNode->varName);
			    if (curNodeData->init == 0)
			    {
				    symtable_add(saveVarName, newID_token(DT_INT, 0, 0, saveVarName, 1));
			    }
			    if (curNodeData->init == 1)
			    {
				    if (curNodeData->var == 1)
				    {
					    symtable_add(saveVarName, newID_token(DT_INT, 1, interpretAST_int(curNode->left), saveVarName, 1));
				    }
				    else if (curNodeData->var == 0)
				    {
					    struct IDENT_tokenData* curID = symtable_getItem(curNodeData->varName);
					    if (curID == NULL)
					    {
						    printf("[SYNTAX ERROR] variable '%s' has not been initialized\n", curNodeData->varName);
						    exit(1);
					    }
					    curID->value = interpretAST_int(curNode->left);
				    }
			    }
			
			    free(curNodeData);
		    }
		curNode = curNode->right;
	}
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
