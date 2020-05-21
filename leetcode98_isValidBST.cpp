#include "include.h"
bool isValidBST(TreeNode* root, int minValue, int maxValue)
{
	if (root == NULL)return true;
	if ((minValue != -1 && root->val <= minValue) || (maxValue != -1 && root->val >= maxValue))
		return false;
	if (!isValidBST(root->left, minValue, root->val) || !isValidBST(root->right, root->val, maxValue))
		return false;
	return true;
}
bool isValidBST(TreeNode* root)
{
	return isValidBST(root, -1, -1);
}


bool isValidBST2(TreeNode* root) 
{
	if (root==NULL)return false;
	TreeNode* lc = root->left;
	TreeNode* rc = root->right;
	if (lc == NULL && rc == NULL)return true;
	bool left_valid(false);
	bool right_valid(false);
	if (lc!=NULL)
	{
		if (isValidBST(lc))
		{
			while (lc->right != NULL)
			{
				lc = lc->right;
			}
			int lmax = lc->val;
			left_valid = lmax < root->val;
		}
	}
	if (rc!=NULL)
	{
		if (isValidBST(rc))
		{
			while (rc->left != NULL)
			{
				rc = rc->left;
			}
			int rmin = rc->val;
			right_valid = rmin > root->val;
		}
	}
	
	if (lc == NULL && rc != NULL)return right_valid;
	if (rc == NULL && lc != NULL)return left_valid;
	return left_valid && right_valid;
}