#include "include.h"
int treeDepth(TreeNode* root)
{
	if (root == NULL)return 0;
	return max(treeDepth(root->left), treeDepth(root->right)) + 1;
}
bool isBalanced(TreeNode* root) 
{
	if (root == NULL)return true;
	return isBalanced(root->left) && isBalanced(root->right) && abs(treeDepth(root->left) - treeDepth(root->right)) < 2;
}