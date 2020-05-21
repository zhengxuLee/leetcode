#include "include.h"
TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder) 
{
	if (inorder.empty() && postorder.empty())return NULL;
	int root = postorder.back();
	vector<int>leftInorder(inorder.begin(), find(inorder.begin(), inorder.end(), root));
	vector<int>rightInorder(find(inorder.begin(), inorder.end(), root)+1, inorder.end());
	vector<int>leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
	vector<int>rightPostorder(postorder.begin() + leftInorder.size(), --postorder.end());
	TreeNode* _root = new TreeNode(root);
	TreeNode* _left = buildTree2(leftInorder, leftPostorder);
	TreeNode* _right = buildTree2(rightInorder, rightPostorder);
	_root->left = _left;
	_root->right = _right;
	return _root;
}