#include "include.h"

/*
Given a Binary Search Tree (BST), 
convert it to a Greater Tree such that 
every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

Example:

Input: The root of a Binary Search Tree like this:
  5
/   \
2     13

Output: The root of a Greater Tree like this:
  18
/   \
20   13


*/


/*
void InorderVisit(TreeNode* root,vector<TreeNode*>&list)
{
if(root==NULL)return;
InorderVisit(root->left,list);
list.push_back(root);
InorderVisit(root->right,list);
return;
}
TreeNode* convertBST(TreeNode* root)
{
if(root==NULL)return NULL;
if(root->left==NULL && root->right==NULL)return root;
vector<TreeNode*>list;
InorderVisit(root,list);
for(int i=list.size()-2;i>=0;--i)
{
list[i]->val+=list[i+1]->val;
}
return root;
}
*/
int sum = 0;
TreeNode* convertBST(TreeNode* root)
{
	if (root == NULL)return NULL;
	if (root != NULL)
	{
		convertBST(root->right);
		sum += root->val;
		root->val = sum;
		convertBST(root->left);
	}
	return root;
}