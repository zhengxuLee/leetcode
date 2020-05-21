#include "include.h"

/*
Given two non-empty binary trees s and t, 
check whether tree t has exactly the same structure and node values with a subtree of s. 
A subtree of s is a tree consists of a node in s and all of this node's descendants. 
The tree s could also be considered as a subtree of itself.

*/

bool isEqual(TreeNode* s, TreeNode* t)
{
	if (s == NULL && t == NULL)return true;
	if (s == NULL || t == NULL)return false;
	if (s->val != t->val)return false;
	return isEqual(s->left, t->left) && isEqual(s->right, t->right);
}
bool isSubtree(TreeNode* s, TreeNode* t)
{
	if (s == NULL && t == NULL)return true;
	if (s == NULL || t == NULL)return false;
	if (isEqual(s, t))return true;
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}