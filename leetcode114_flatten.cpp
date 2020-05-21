#include "include.h"
/*
Given a binary tree, flatten it to a linked list in-place.
For example, given the following tree:
       1
	  / \
	 2   5
	/ \   \
   3   4   6
The flattened tree should look like:
1
\
 2
  \
   3
    \
     4
      \
       5
        \
		 6*/
TreeNode* lastNode = NULL;//上一次访问的节点
void flatten1(TreeNode* root)
{
	if (root == NULL)return;
	TreeNode* lc = root->left;
	TreeNode* rc = root->right;
	if (lastNode != NULL)
	{
		lastNode->left = NULL;
		lastNode->right = root;
	}
	lastNode = root;
	flatten1(lc);
	flatten1(rc);
}


void flatten(TreeNode* root)
{
	if (root == NULL)return;
	TreeNode* _left = root->left;
	TreeNode* _right = root->right;
	flatten(_left);
	flatten(_right);
	root->left = NULL;
	root->right = _left;
	while (root->right != NULL)
	{
		root = root->right;
	}
	root->right = _right;
}