#include "include.h"

/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

     10
    /  \
   5   -3
  / \    \
 3   2   11
    / \   \
   3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
*/

int path(TreeNode* root, int sum)
{
	if (root == NULL)return 0;
	int add = root->val == sum ? 1 : 0;
	return add + path(root->left, sum - root->val) + path(root->right, sum - root->val);
}
int pathSum(TreeNode* root, int sum)
{
	if (root == NULL)return 0;
	//include root
	int include = path(root, sum);
	//donnot include root
	int without = pathSum(root->left, sum) + pathSum(root->right, sum);
	return include + without;
}