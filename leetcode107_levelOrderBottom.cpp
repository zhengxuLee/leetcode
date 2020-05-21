#include "include.h"

vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
	vector<vector<int>>res_vvOrder;
	if (root == NULL)return res_vvOrder;
	queue<TreeNode*>myQueue;
	myQueue.push(root);
	while (!myQueue.empty())
	{
		vector<int>levelValues;
		int size = myQueue.size();
		for (int i = 0; i < size;++i)
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
			levelValues.push_back(_front->val);
		}
		res_vvOrder.insert(res_vvOrder.begin(), levelValues);
	}
	return res_vvOrder;
}