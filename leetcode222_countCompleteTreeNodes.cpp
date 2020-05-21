#include "include.h"
/*
Given a complete binary tree, count the number of nodes.
*/
int countNodes(TreeNode* root) 
{
	if (root == NULL)
		return 0;
	int left = 0;
	int right = 0;
	TreeNode* p1 = root;
	TreeNode* p2 = root;
	while (p1 != NULL)
	{
		p1 = p1->left;
		++left;
	}
	while (p2 != NULL)
	{
		p2 = p2->right;
		++right;
	}
	if (left == right)
		return (1 << left) - 1;
	else
		return countNodes(root->left) + countNodes(root->right) + 1;
}