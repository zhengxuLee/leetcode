#include "include.h"
bool isSymmetric(TreeNode* p,TreeNode* q) 
{
	if (p == NULL && q == NULL)return true;
	if (p == NULL || q == NULL)return false;
	if (p->val != q->val)return false;
	return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
}
bool isSymmetric(TreeNode* root) 
{
	if (root == NULL)return true;
	return isSymmetric(root->left, root->right);
}