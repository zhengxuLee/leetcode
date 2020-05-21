#include "include.h"

vector<vector<int>> levelOrder(TreeNode* root) 
{
	vector<vector<int>>res_vvlevelOrder;
	if (root == NULL)return res_vvlevelOrder;
	queue<TreeNode*>myQueue;
	myQueue.push(root);
	int count = 0;
	while (!myQueue.empty())
	{
		vector<int>level_values;
		count = myQueue.size();
		for (int i = 0; i<count; ++i)
		{
			TreeNode* _front = myQueue.front();
			myQueue.pop();
			if (_front->left != NULL)
			{
				myQueue.push(_front->left);
			}
			if (_front->right != NULL)
			{
				myQueue.push(_front->right);
			}
			level_values.push_back(_front->val);
		}
		res_vvlevelOrder.push_back(level_values);
	}
	return res_vvlevelOrder;
}