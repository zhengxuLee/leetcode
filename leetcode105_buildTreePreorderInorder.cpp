#include "include.h"
TreeNode* buildTree1(vector<int>& preorder, vector<int>& inorder) 
{
	//µÝ¹é»ù
	if (preorder.empty() && inorder.empty())return NULL;
	//·ÖÖÎ
	int root = preorder[0];
	vector<int>left_inorder(inorder.begin(), find(inorder.begin(), inorder.end(), root));
	vector<int>right_inorder(find(inorder.begin(), inorder.end(), root) + 1, inorder.end());
	vector<int>left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
	vector<int>right_preorder(preorder.begin() + 1 + left_inorder.size(), preorder.end());
	TreeNode* _root = new TreeNode(root);
	TreeNode* _left = buildTree1(left_preorder, left_inorder);
	TreeNode* _right = buildTree1(right_preorder, right_inorder);
	_root->left = _left;
	_root->right = _right;
	return _root;
}

