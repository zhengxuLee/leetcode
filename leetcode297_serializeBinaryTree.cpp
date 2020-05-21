#include "include.h"
/*
Serialization is the process of converting a data structure 
or object into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later in the same 
or another computer environment.

Design an algorithm to serialize and deserialize a binary tree.
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
*/

// Encodes a tree to a single string.
string serialize(TreeNode* root)
{
	if (root == NULL)
		return string("#,");
	string s;
	s += to_string(root->val);
	s.push_back(',');
	return s + serialize(root->left) + serialize(root->right);
}


// Decodes your encoded data to tree.
TreeNode* deserialize(const string& data, int &index)
{
	if (data.empty())return NULL;
	while (index < data.length() && data[index] == ',')
		++index;
	if (index >= data.length())
		return NULL;
	if (data[index] == '#')
	{
		++index;
		return NULL;
	}
	int sign = 1;
	if (data[index] == '-')
	{
		sign = -1;
		++index;
	}
	int val = 0;
	while (index < data.length() && isdigit(data[index]))
	{
		val = 10 * val + data[index] - '0';
		++index;
	}
	TreeNode* root = new TreeNode(sign*val);
	root->left = deserialize(data, index);
	root->right = deserialize(data, index);
	return root;
}

TreeNode* deserialize(string data)
{
	int index = 0;
	return deserialize(data, index);
}
