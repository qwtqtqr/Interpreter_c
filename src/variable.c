#include "header/symtable.h"
#include "header/ast.h"
#include "header/tokens.h"
#include "header/symtable.h"
#include <stdio.h>


struct AST_Node* genVarAST()
{
	struct AST_Node* node = NULL, * left = NULL, * right = NULL;
	if (currentToken->tokenType == TT_VAR)
	{
		scan_curToken();
		if (currentToken->tokenType != TT_IDENT)
		{
			printf("[SYNTAX ERROR] identifier is missing (Line %d)\n", Line);
			exit(1);
		}

		struct Token* identToken = currentToken;
		printf("curTT:  %s\n", identToken->tokenType);
		scan_curToken();
		if (currentToken->tokenType == TT_EQUALS)
		{
			left = binexpr_int(0);
			//right = genMainAST();
			printf("iT:  %s\n", identToken->IdentToken_name);
			node = mkastnode_ident(TT_IDENT, 0, 0, left, genMainAST(), newIdentToken(DT_INT, 1, 0,(const char*) identToken->IdentToken_name), identToken->IdentToken_name);
			return node;
		}
		else if (currentToken->tokenType == TT_OP_END)
		{
			node = mkastnode_ident(TT_IDENT, 0, 0, left, genMainAST(), newIdentToken(DT_INT, 0, 0,identToken->IdentToken_name), identToken->IdentToken_name);
			return node;

		}
		else
		{
			printf("[SYNTAX ERROR] Line %d\n", Line);
			exit(1);
		}
	}
	return node;
}