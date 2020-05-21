#include "include.h"
/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

//Definition for binary tree
//直接获取中序遍历序列
class BSTIterator {
public:
	BSTIterator(TreeNode *root)
	{
		while (root != NULL)
		{
			myStack.push(root);
			root = root->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		return !myStack.empty();
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode* top = myStack.top();
		myStack.pop();
		TreeNode* current = top->right;
		while (current != NULL)
		{
			myStack.push(current);
			current = current->left;
		}
		return top->val;
	}
private:
	stack<TreeNode*>myStack;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/