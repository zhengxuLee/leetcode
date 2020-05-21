#include "include.h"
vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
	vector<vector<int>>res_vvNodeValues;
	if (root == NULL)return res_vvNodeValues;
	if (root->left == NULL && root->right == NULL && root->val == sum)
	{
		vector<int>path = { root->val };
		res_vvNodeValues.push_back(path);
		return res_vvNodeValues;
	}
	vector<vector<int>>left_path = pathSum(root->left, sum - root->val);
	for (auto path:left_path)
	{
		path.insert(path.begin(), root->val);
		res_vvNodeValues.push_back(path);
	}
	vector<vector<int>>right_path = pathSum(root->right, sum - root->val);
	for (auto path : right_path)
	{
		path.insert(path.begin(), root->val);
		res_vvNodeValues.push_back(path);
	}
	return res_vvNodeValues;
}