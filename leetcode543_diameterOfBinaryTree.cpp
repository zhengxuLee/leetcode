#include "include.h"

/*
Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

Example:
Given a binary tree
   1
  / \
 2   3
/ \
4   5
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.

*/
int diameter = 0;
int depth(TreeNode* root)
{
	if (root == NULL)return 0;
	int L = depth(root->left);
	int R = depth(root->right);
	diameter = max(diameter, L + R + 1);
	return max(L, R) + 1;
}
int diameterOfBinaryTree1(TreeNode* root)
{
	if (root == NULL)return 0;
	depth(root);
	return diameter - 1;
}


int treeDepth(TreeNode* root)
{
	if (root == NULL)return 0;
	return max(treeDepth(root->left), treeDepth(root->right)) + 1;
}
int diameterOfBinaryTree2(TreeNode* root)
{
	if (root == NULL)return 0;
	//include
	int include = treeDepth(root->left) + 1 + treeDepth(root->right);
	//not include
	int without = max(diameterOfBinaryTree2(root->left), diameterOfBinaryTree2(root->right));
	return max(include - 1, without);
}