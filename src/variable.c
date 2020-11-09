#include "header/ast.h"
#include "header/scan.h"
#include "header/data.h"


struct AST_Node* genVarAST()
{
	struct AST_Node* node = NULL;
	//if (currentToken->tokenType == TT_VAR)
	//{
		scan_curToken();

		if (currentToken->tokenType != TT_IDENT)
		{
			printf("[SYNTAX ERROR] expected an identifier (Line %d)\n", Line);
			exit(1);
		}
		struct Token* ID_token = currentToken;
		char* varName = calloc(strlen(ID_token->IdentToken_name), sizeof(char));
		varName = strcpy(varName, ID_token->IdentToken_name);
		scan_curToken();

		if (currentToken->tokenType == TT_OP_END)
		{
			node = mkastnode_ident(TT_IDENT, 0, 0, NULL, NULL, newID_token(DT_INT, 0, 0, varName), varName);
			scan_curToken();
			return node;
		}
		else if (currentToken->tokenType == TT_EQUALS)
		{
			node = mkastnode_ident(TT_IDENT, 0, 0, binexpr_int(0), NULL, newID_token(DT_INT, 1, 0, varName), varName);
			return node;
		}

		printf("[SYNTAX ERROR] Line %d\n", Line);
		exit(1);

	//}
	return node;
}