#include "ast.h"

#include "bison.tab.h"
void RPN_Walk(TreeNode *aux)
{
	if (aux)
	{
		RPN_Walk(aux->left);
		RPN_Walk(aux->right);
		switch (aux->node_type)
		{
		case ADD:
		{
			printf("+ ");
		};
		break;
		case SUB:
		{
			printf("- ");
		};
		break;
		case MULT:
		{
			printf("* ");
		};
		break;
		case DIV:
		{
			printf("/ ");
		};
		break;
		case NUM_FLOAT:
		{
			printf("%f ", aux->value);
		};
		break;
		case IDENTIFIER:
		{	
			printf("%s ", aux->name);
		};
		break;
		case EXP:
		{
			printf("^ ");
		};
		break;
		case MOD:
		{
			printf("%% ");
		};
		break;
		case SEN:
		{
			printf("SEN ");
		};
		break;
		case COS:
		{
			printf("COS ");
		};
		break;
		case TAN:
		{
			printf("TAN ");
		};
		break;
		case X:
		{
			printf("x ");
		};
		break;
		default:
		{
			printf("ERROR: INVALID TYPE ");
		};
		break;
		}
	}
}
void Delete_Tree(TreeNode *aux)
{
	if (aux)
	{
		Delete_Tree(aux->left);
		Delete_Tree(aux->right);
		free(aux);
	}
}

TreeNode *createTreeNode(int type, TreeNode *left, TreeNode *right, float value)
{
	TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
	new_node->node_type = type;
	new_node->left = left;
	new_node->right = right;
	new_node->value = value;
	new_node->name = NULL;
	return new_node;
}

TreeNode *createTreeNodeIdent(int type, TreeNode *left, TreeNode *right, char* name)
{
	TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
	new_node->node_type = type;
	new_node->left = left;
	new_node->right = right;
	new_node->value = 0;
	new_node->name = strdup(name);
	return new_node;
}

float CalculateExpression( Hashtable* ht, TreeNode* root){
	if(root){
		float left = CalculateExpression(ht, root->left);
		float right = CalculateExpression(ht, root->right);
		switch (root->node_type)
		{
		case ADD:
		{
			return left + right;
		};
		break;
		case SUB:
		{
			return left - right;
		};
		break;
		case MULT:
		{
			return left * right;
		};
		break;
		case DIV:
		{
			return left / right;
		};
		break;
		case NUM_FLOAT:
		{
			return root->value;
		};
		break;
		case IDENTIFIER:
		{	
			varTypes* temp = search(ht, root->name);
			if(temp == NULL){
				printf("Undefined Symbol [%s]\n", root->name);
				return 0;
			}
			if(temp->type == 1){
				return *getFloat(temp);
			}
			else{
				printf("ERROR: INVALID IDENTIFIER TYPE\n");
				return 0;
			}
			
		};
		break;
		case EXP:
		{
			return pow(left, right);
		};
		break;
		case MOD:
		{
			return fmod(left, right);
		};
		break;
		case SEN:
		{
			return sin(left);
		};
		break;
		case COS:
		{
			return cos(left);
		};
		break;
		case TAN:
		{
			return tan(left);
		};
		break;
		case X:
		{
			printf("ERROR: X NOT SUPPORTED IN CALCULATION\n");
			return 0;
		};
		break;
		default:
		{
			printf("ERROR: INVALID TYPE ");
			return 0;
		};
		break;
		}
	}
	return 0;
}