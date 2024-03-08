#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "varTypes.h"
#include "hashtable.h"
#include <math.h>


typedef struct TreeNode
{
	int node_type;
	float value;
	char* name;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;
void RPN_Walk(TreeNode *aux);
void Delete_Tree(TreeNode *aux);
TreeNode *createTreeNode(int type, TreeNode *left, TreeNode *right, float value);
TreeNode *createTreeNodeIdent(int type, TreeNode *left, TreeNode *right, char* name);

#endif