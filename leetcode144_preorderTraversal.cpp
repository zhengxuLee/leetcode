#include "include.h"

vector<int> preorderTraversal(TreeNode* root) 
{
	vector<int>preOrder;
	if (root == NULL)return preOrder;
	stack<TreeNode*>myStack;
	myStack.push(root);
	while (!myStack.empty())
	{
		TreeNode* top = myStack.top();
		myStack.pop();
		preOrder.push_back(top->val);
		if (top->right != NULL)
			myStack.push(top->right);
		if (top->left != NULL)
			myStack.push(top->left);
	}
	return preOrder;
}