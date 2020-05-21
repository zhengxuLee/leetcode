#include "include.h"
#include <numeric>

/*
Given a non-empty binary tree, find the maximum path sum.
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The path must contain at least one node and does not need to go through the root.

Example 1:
Input: [1,2,3]
	 1
	/ \
   2   3
Output: 6

Example 2:
Input: [-10,9,20,null,null,15,7]
	-10
	/ \
   9  20
	 /  \
	15   7
Output: 42

*/
int maxSum = INT_MIN;
int pathSumExtendToCurrentNode(TreeNode* current)
{
	if (current == NULL)return 0;
	int exl = max(pathSumExtendToCurrentNode(current->left), 0);
	int exr = max(pathSumExtendToCurrentNode(current->right), 0);
	maxSum = max(exl + current->val + exr, maxSum);
	return max(exl, exr) + current->val;
}
int maxPathSum(TreeNode* root) 
{
	if (root == NULL)return 0;
	pathSumExtendToCurrentNode(root);
	return maxSum;
}