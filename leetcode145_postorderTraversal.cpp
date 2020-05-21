#include "include.h"
void GoAlongLeftRecordLeftAndRight(stack<TreeNode*>&myStack)
{
	while (true)
	{
		TreeNode* root = myStack.top();
		if (root->left == NULL && root->right == NULL)
		{
			break;
		}
		if (root->right != NULL)
		{
			myStack.push(root->right);
		}
		if (root->left!=NULL)
		{
			myStack.push(root->left);
		}
	}
}
vector<int> postorderTraversal(TreeNode* root)
{
	vector<int>postOrder;
	if (root == NULL)return postOrder;
	stack<TreeNode*>myStack;
	myStack.push(root);
	while (!myStack.empty())
	{
		if (myStack.top()->left!=root && myStack.top()->right!=root)
		{
			GoAlongLeftRecordLeftAndRight(myStack);
		}
		root = myStack.top();
		myStack.pop();
		postOrder.push_back(root->val);
	}
	return postOrder;
}