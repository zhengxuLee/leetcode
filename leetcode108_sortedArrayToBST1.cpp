#include "include.h"
TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end)
{
	if (nums.empty())return NULL;
	if (start >= end)return NULL;
	int middle = (start + end) / 2;
	TreeNode* _root = new TreeNode(nums[middle]);
	TreeNode* _left = sortedArrayToBST(nums, start, middle);
	TreeNode* _right = sortedArrayToBST(nums, middle + 1, end);
	_root->left = _left;
	_root->right = _right;
	return _root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	if (nums.empty())return NULL;
	return sortedArrayToBST(nums, 0, nums.size());
}