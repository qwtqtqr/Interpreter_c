#include "header/ast.h"
#include "header/data.h"
#include "header/scan.h"
#include "header/tokens.h"
#include "header/list.h"
#include "header/symtable.h"
#include <math.h>


static struct DATA_STRUCT* RETURN_DATATYPE_NUM(struct DATA_STRUCT* leftVal, struct DATA_STRUCT* rightVal, int OP, int dt_left, int dt_right)
{
	int init = 0;
	long double* result = malloc(sizeof(long double));
	switch (OP)
	{
	case TT_PLUS:
		if (dt_left == DT_FLOAT && dt_right == DT_FLOAT) 
		{
			*result = *(leftVal->doubleVal) + *(rightVal->doubleVal);
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_FLOAT)
		{ 
			*result = *(leftVal->intVal) + *(rightVal->doubleVal);
			init = 1;
		}
		if (dt_left == DT_FLOAT && dt_right == DT_INT)
		{
			*result = *(leftVal->doubleVal) + *(rightVal->intVal);
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_INT)
		{
			long long* result = malloc(sizeof(long long));
			*result = *(leftVal->intVal) + *(rightVal->intVal);
			free(leftVal), free(rightVal);
			return new_DATA_STRUCT(NULL, NULL, NULL, result, NULL, DT_INT);
		}
		break;

	case TT_MINUS:
		if (dt_left == DT_FLOAT && dt_right == DT_FLOAT)
		{
			*result = *(leftVal->doubleVal) - *(rightVal->doubleVal);
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_FLOAT)
		{
			*result = *(leftVal->intVal) - *(rightVal->doubleVal);
			init = 1;
		}
		if (dt_left == DT_FLOAT && dt_right == DT_INT)
		{
			*result = *(leftVal->doubleVal) - *(rightVal->intVal);
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_INT)
		{
			long long* result = malloc(sizeof(long long));
			*result = *(leftVal->intVal) - *(rightVal->intVal);
			free(leftVal), free(rightVal);
			return new_DATA_STRUCT(NULL, NULL, NULL, result, NULL, DT_INT);
		}
		break;

	case TT_MUL:
		if (dt_left == DT_FLOAT && dt_right == DT_FLOAT)
		{
			*result = *(leftVal->doubleVal) * *(rightVal->doubleVal);
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_FLOAT)
		{
			*result = *(leftVal->intVal) * *(rightVal->doubleVal);
			init = 1;
		}
		if (dt_left == DT_FLOAT && dt_right == DT_INT)
		{
			*result = *(leftVal->doubleVal) * *(rightVal->intVal);
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_INT)
		{
			long long* result = malloc(sizeof(long long));
			*result = *(leftVal->intVal) * *(rightVal->intVal);
			free(leftVal), free(rightVal);
			return new_DATA_STRUCT(NULL, NULL, NULL, result, NULL, DT_INT);
		}
		break;

	case TT_DIV:
		if (dt_left == DT_FLOAT && dt_right == DT_FLOAT)
		{
			*result = *(leftVal->doubleVal) / *(rightVal->doubleVal);
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_FLOAT)
		{
			*result = *(leftVal->intVal) / *(rightVal->doubleVal);
			init = 1;
		}
		if (dt_left == DT_FLOAT && dt_right == DT_INT)
		{
			*result = *(leftVal->doubleVal) / *(rightVal->intVal);
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_INT)
		{
			long double* result = malloc(sizeof(long long));
			*result =(long double) *(leftVal->intVal) / (long double)*(rightVal->intVal);
			free(leftVal), free(rightVal);
			return new_DATA_STRUCT(NULL, NULL, result, NULL, NULL, DT_FLOAT);
		}
		break;

	case TT_POW:
		if (dt_left == DT_FLOAT && dt_right == DT_FLOAT)
		{
			*result = pow(*(leftVal->doubleVal), *(rightVal->doubleVal));
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_FLOAT)
		{
			*result = pow(*(leftVal->intVal), *(rightVal->doubleVal));
			init = 1;
		}
		if (dt_left == DT_FLOAT && dt_right == DT_INT)
		{
			*result = pow(*(leftVal->doubleVal), *(rightVal->intVal));
			init = 1;
		}
		if (dt_left == DT_INT && dt_right == DT_INT)
		{
			long long* result = malloc(sizeof(long long));
			*result = pow(*(leftVal->intVal), *(rightVal->intVal));
			free(leftVal), free(rightVal);
			return new_DATA_STRUCT(NULL, NULL, NULL, result, NULL, DT_INT);
		}
		break;

	}
	free(leftVal), free(rightVal);
	long long res_long = *result;
	if (init == 0)
	{
		printf("[ERROR] invalid datatype\n");
		exit(1);
	}
	if ((*result / res_long) == 1)
	{
		long long* res_int = malloc(sizeof(long long));
		*res_int = (long long)*result;
		free(result);
		return new_DATA_STRUCT(NULL, NULL, NULL, res_int, NULL, DT_INT);
	}
	return new_DATA_STRUCT(NULL, NULL, result, NULL, NULL, DT_FLOAT);
}




struct DATA_STRUCT* interpretAST_int(struct AST_Node* root)
{
	struct DATA_STRUCT *leftVal = NULL, *rightVal = NULL;
	struct IDENT_tokenData* curIdent = NULL;
	struct tableNode* tNode = NULL;

	if (root->left != NULL)
	{
		leftVal = interpretAST_int(root->left);
	}
	if (root->right != NULL) {
		rightVal = interpretAST_int(root->right);
	}

	int dt_left = -1; 
	int dt_right = -1;

	if (leftVal != NULL)
	{
		dt_left = leftVal->dataType;
	}
	if (rightVal != NULL)
	{
		dt_right = rightVal->dataType;
	}

	switch (root->tokenType)
	{
	case TT_PLUS:
		return(RETURN_DATATYPE_NUM(leftVal, rightVal, TT_PLUS, dt_left, dt_right));

	case TT_MINUS:
		return(RETURN_DATATYPE_NUM(leftVal, rightVal, TT_MINUS, dt_left, dt_right));

	case TT_MUL:
		return(RETURN_DATATYPE_NUM(leftVal, rightVal, TT_MUL, dt_left, dt_right));

	case TT_DIV:
		return(RETURN_DATATYPE_NUM(leftVal, rightVal, TT_DIV, dt_left, dt_right));

	case TT_POW:
		return(RETURN_DATATYPE_NUM(leftVal, rightVal, TT_POW, dt_left, dt_right));

	case TT_INT:
		return root->data;

	case TT_FLOAT:
		return root->data;

	case TT_IDENT:
		curIdent = (struct IDENT_tokenData*)symtable_getItem(root->varName);
		if (curIdent == NULL)
		{
			printf("[ERROR] variable does not exist\n");
			exit(1);
		}
		int dt = curIdent->data->dataType;

		if (dt == DT_INT)
		{
			*(curIdent->data->intVal) *= root->intVal;
		}
		else if (dt == DT_FLOAT)
		{
			*(curIdent->data->doubleVal) *= root->intVal;
		}
		else 
		{
			printf("[ERROR] invalid datatype\n");
			exit(1);
		}
		return DATA_STRUCT_cpy(curIdent->data);
	}
}


void interpretMainAST(struct AST_Node* root)
{
	struct AST_Node* curNode = root;
	while (curNode != NULL)
	{
		if (curNode->tokenType == TT_PRINT)
		{
			struct DATA_STRUCT* printVal_struct = interpretAST_int(curNode->left);
			int struct_dt = printVal_struct->dataType;
			if (struct_dt == DT_INT)
			{
				printf("%lld\n", *(printVal_struct->intVal));
			}
			else if (struct_dt == DT_FLOAT)
			{
				printf("%Lf\n", *(printVal_struct->doubleVal));
			}
		}

		else if (curNode->tokenType == TT_IDENT)
		{
			struct IDENT_tokenData* curNodeData = (struct IDENT_tokenData*)curNode->otherData;
			char* saveVarName = calloc(strlen(curNode->varName), sizeof(char));
			saveVarName = strcpy(saveVarName, curNode->varName);
			if (curNodeData->init == 0)
			{
				symtable_add(saveVarName, newID_token(DT_INT, 0, 0, saveVarName, 1, new_DATA_STRUCT(NULL, NULL, NULL, NULL, NULL, -1)));
			}
			if (curNodeData->init == 1)
			{
				if (curNodeData->var == 1)
				{
					symtable_add(saveVarName, newID_token(DT_INT, 1, 0, saveVarName, 1, interpretAST_int(curNode->left)));
				}
				else if (curNodeData->var == 0)
				{
					struct IDENT_tokenData* curID = symtable_getItem(curNodeData->varName);
					if (curID == NULL)
					{
						printf("[SYNTAX ERROR] variable '%s' has not been initialized\n", curNodeData->varName);
						exit(1);
					}
					curID->data = interpretAST_int(curNode->left);
				}
			}

			free(curNodeData);
		}

		// todo: free ident_node
		else if (curNode->tokenType == TT_UNDEF)
		{
			symtable_removeItem(curNode->left->varName);
		}

		curNode = curNode->right;
	}
}

