#include "include.h"
vector<TreeNode*>generateSubTree(int start, int end)
{
	vector<TreeNode*>res_tree;
	if (start > end)
	{
		res_tree.push_back(NULL);
		return res_tree;
	}
	for (int i = start; i <= end; ++i)
	{
		vector<TreeNode*>ltrees = generateSubTree(start, i - 1);
		vector<TreeNode*>rtrees = generateSubTree(i + 1, end);
		for (int j = 0; j < ltrees.size(); ++j)
		{
			for (int k = 0; k < rtrees.size(); ++k)
			{
				TreeNode* root = new TreeNode(i);
				root->left = ltrees[j];
				root->right = rtrees[k];
				res_tree.push_back(root);
			}
		}
	}
	return res_tree;
}

vector<TreeNode*> generateTrees(int n)
{
	vector<TreeNode*> res_nodes;
	if (n < 1)return res_nodes;
	res_nodes = generateSubTree(1, n);
	return res_nodes;
}

