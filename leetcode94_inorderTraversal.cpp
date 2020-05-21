#include "include.h"
#include <stack>

vector<int> inorderTraversal(TreeNode* root)
{
	vector<int>travelVec;
	if (root == NULL)return travelVec;
	stack<TreeNode*>myStack;
	while (true)
	{
		if (root!=NULL)
		{
			myStack.push(root);
			root = root->left;
		}
		else if (!myStack.empty())
		{
			TreeNode* top = myStack.top();
			travelVec.push_back(top->val);
			myStack.pop();
			root = top->right;
		}
		else
		{
			break;
		}
	}
	return travelVec;
}