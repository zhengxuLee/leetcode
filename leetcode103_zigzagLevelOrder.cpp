#include "include.h"
#include <stack>
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
	vector<vector<int>>res_vvlevelOrder;
	if (root == NULL)return res_vvlevelOrder;
	stack<TreeNode*>myStack1;
	stack<TreeNode*>myStack2;
	myStack1.push(root);
	while (!myStack1.empty() || !myStack2.empty())
	{
		vector<int>level_values1;
		int size1 = myStack1.size();
		for (int i = 0; i < size1; ++i)
		{
			TreeNode* _top1 = myStack1.top();
			myStack1.pop();
			if (_top1->left != NULL)
			{
				myStack2.push(_top1->left);
			}
			if (_top1->right != NULL)
			{
				myStack2.push(_top1->right);
			}
			level_values1.push_back(_top1->val);
		}
		if (!level_values1.empty())res_vvlevelOrder.push_back(level_values1);

		vector<int>level_values2;
		int size2 = myStack2.size();
		for (int j = 0; j < size2; ++j)
		{
			TreeNode* _top2 = myStack2.top();
			myStack2.pop();
			if (_top2->right != NULL)
			{
				myStack1.push(_top2->right);
			}
			if (_top2->left != NULL)
			{
				myStack1.push(_top2->left);
			}
			level_values2.push_back(_top2->val);
		}
		if (!level_values2.empty())res_vvlevelOrder.push_back(level_values2);
	}
	return res_vvlevelOrder;
}
