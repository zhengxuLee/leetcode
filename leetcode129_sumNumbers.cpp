#include "include.h"
vector<vector<int>>helper(TreeNode* root)
{
	vector<vector<int>>root_paths;
	if (root == NULL)return root_paths;
	if (root->left == NULL && root->right == NULL)
	{
		vector<int>path = { root->val };
		root_paths.push_back(path);
		return root_paths;
	}
	vector<vector<int>> left_paths = helper(root->left);
	vector<vector<int>> right_paths = helper(root->right);
	for (auto path:left_paths)
	{
		path.insert(path.begin(), root->val);
		root_paths.push_back(path);
	}
	for (auto path : right_paths)
	{
		path.insert(path.begin(), root->val);
		root_paths.push_back(path);
	}
	return root_paths;
}
int sumNumbers(TreeNode* root) 
{
	if (root == NULL)return 0;
	int res = 0;
	vector<vector<int>>paths = helper(root);
	for (auto path:paths)
	{
		int num = 0;
		for (int i = 0; i < path.size();++i)
		{
			num = num * 10 + path[i];
		}
		res += num;
	}
	return res;
}


//int sumNumbers(TreeNode* root) {
//	int sum = 0;
//	if (root == NULL) return sum;
//	recursion(root, root->val, sum);
//	return sum;
//}
//
//void recursion(TreeNode* p, int current, int& sum) {
//	if (p->left == NULL && p->right == NULL) {
//		sum += current;
//		return;
//	}
//	if (p->left) recursion(p->left, current * 10 + p->left->val, sum);
//	if (p->right) recursion(p->right, current * 10 + p->right->val, sum);
//}