#include "include.h"
/*
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.

Example 1:
Input: [1,3,null,null,2]
	 1
	/
	3
	\
	 2
Output: [3,1,null,null,2]

	 3
	/
	1
	\
	 2

Example 2:
Input: [3,1,4,null,null,2]
	 3
	/ \
   1   4
  /
 2
Output: [2,1,4,null,null,3]

	 2
	/ \
   1   4
      /
	 3
Follow up:
A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/
//获取中序遍历序列，找到其中第一个不满足中序递增的节点，和最后一个小于他的节点，二者交换值域即可
void GoAlongLeftAndPushStack(TreeNode* current, stack<TreeNode*>&myStack)
{
	if (current == NULL)return;
	while (current!=NULL)
	{
		myStack.push(current);
		current = current->left;
	}
}
void InorderVisit(TreeNode* root, vector<TreeNode*>& inOrder)
{
	if (root == NULL)return;
	stack<TreeNode*>myStack;
	GoAlongLeftAndPushStack(root, myStack);
	while (!myStack.empty())
	{
		TreeNode* node = myStack.top();
		myStack.pop();
		inOrder.push_back(node);
		GoAlongLeftAndPushStack(node->right, myStack);
	}
}
void recoverTree(TreeNode* root) 
{
	vector<TreeNode*> inOrder;
	InorderVisit(root, inOrder);
	for (int i = 0; i < inOrder.size()-1;++i)
	{
		if (inOrder[i]->val>inOrder[i+1]->val)
		{
			TreeNode* swapWith(NULL);
			for (int j = i + 1; j < inOrder.size();++j)
			{
				if (inOrder[j]->val<inOrder[i]->val)
				{
					swapWith = inOrder[j];
				}
			}
			swap(inOrder[i]->val, swapWith->val);
			break;
		}
	}
}