#include "include.h"
struct TreeLinkNode
{
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
};
void connect(TreeLinkNode *root)
{
	if (root == NULL)return;
	queue<TreeLinkNode*>myQueue;
	myQueue.push(root);
	while (!myQueue.empty())
	{
		int size = myQueue.size();
		TreeLinkNode* current(NULL);
		for (int i = 0; i < size; ++i)
		{
			TreeLinkNode* _front = myQueue.front();
			myQueue.pop();
			if (_front->left != NULL)
				myQueue.push(_front->left);
			if (_front->right != NULL)
				myQueue.push(_front->right);
			if (current == NULL)
			{
				current = _front;
			}
			else
			{
				current->next = _front;
				current = _front;
			}
		}
	}
}

void connect_r(TreeLinkNode *root)
{
	if (root == NULL) return;
	if (root->left && root->right) root->left->next = root->right;
	if (root->right && root->next) root->right->next = root->next->left;
	connect_r(root->left);
	connect_r(root->right);
}