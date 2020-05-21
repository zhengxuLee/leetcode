#include "include.h"

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:
Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

	  1            <---
	/   \
   2     3         <---
	\     \
	5     4        <---
*/

//每层取层序遍历的最后一个节点
vector<int> rightSideView1(TreeNode* root)
{
	vector<int>rightViewNodes;
	if (root == NULL)return rightViewNodes;
	queue<TreeNode*>myQueue;
	myQueue.push(root);
	while (!myQueue.empty())
	{
		int size = myQueue.size();
		int i = 0;
		for (; i < size; ++i)
		{
			TreeNode* _front = myQueue.front();
			if (i == size - 1)
			{
				rightViewNodes.push_back(_front->val);
			}
			if (_front->left != NULL)myQueue.push(_front->left);
			if (_front->right != NULL)myQueue.push(_front->right);
			myQueue.pop();
		}
	}
	return rightViewNodes;
}

//利用每层只取一个节点，进行递归
//void dfs(TreeNode* root, int k, vector<int>&rightView)
//{
//	if (root == NULL)return;
//	if (rightView.size() == k)
//	{
//		rightView.push_back(root->val);
//	}
//	dfs(root->right, k + 1, rightView);
//	dfs(root->left, k + 1, rightView);
//}
//
//vector<int> rightSideView1(TreeNode* root)
//{
//	vector<int>rightViewNodes;
//	if (root == NULL)return rightViewNodes;
//	dfs(root, 0, rightViewNodes);
//	return rightViewNodes;
//}

