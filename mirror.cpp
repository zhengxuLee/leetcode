#include "include.h"

TreeNode* mirror(TreeNode* root)
{
	if (root == NULL)return NULL;
	TreeNode* _left = mirror(root->left);
	TreeNode* _right = mirror(root->right);
	root->left = _right;
	root->right = _left;
	return root;
}