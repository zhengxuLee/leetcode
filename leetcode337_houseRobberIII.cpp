#include "include.h"
/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

  3
 / \
2   3
 \   \
  3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

    3
   / \
  4   5
 / \   \
1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

*/

/*int rob(TreeNode* root)
{
if(root==NULL)return 0;
TreeNode* lc=root->left;
TreeNode* rc=root->right;
//robbed
int robbed=root->val;
if(lc!=NULL)
robbed+=rob(lc->left)+rob(lc->right);
if(rc!=NULL)
robbed+=rob(rc->left)+rob(rc->right);
//not robbed;
int notRob=rob(lc)+rob(rc);
return max(robbed,notRob);
}*/

//dp solution
unordered_map<TreeNode*, int>maxValue;
int rob(TreeNode* root)
{
	if (root == NULL)return 0;
	if (maxValue.find(root) != maxValue.end())
	{
		return maxValue[root];
	}
	else
	{
		TreeNode* lc = root->left;
		TreeNode* rc = root->right;
		//robbed
		int robbed = root->val;
		if (lc != NULL)
			robbed += rob(lc->left) + rob(lc->right);
		if (rc != NULL)
			robbed += rob(rc->left) + rob(rc->right);
		//not robbed;
		int notRob = rob(lc) + rob(rc);

		//record
		maxValue[root] = max(robbed, notRob);
		return max(robbed, notRob);
	}
}