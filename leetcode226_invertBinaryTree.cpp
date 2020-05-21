#include "include.h"

/*
Invert a binary tree.

Example:
Input:

    4
  /   \
 2     7
/ \   / \
1  3 6   9

Output:

    4
  /   \
 7     2
/ \   / \
9  6 3   1

*/

TreeNode* invertTree(TreeNode* root)
{
	if (root == NULL)return root;
	TreeNode* l = invertTree(root->left);
	TreeNode* r = invertTree(root->right);
	root->left = r;
	root->right = l;
	return root;
}