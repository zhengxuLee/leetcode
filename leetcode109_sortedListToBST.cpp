#include "include.h"
TreeNode* sortedListToBST(ListNode* head)
{
	if (head==NULL)return NULL;
	if (head->next==NULL)return new TreeNode(head->val);
	int i = 0;
	ListNode* p1 = head;
	while (p1 != NULL)
	{
		p1 = p1->next;
		++ i;
	}
	int middle = i / 2;
	ListNode* p2 = head;
	while (middle > 1)
	{
		p2 = p2->next;
		--middle;
	}
	TreeNode* _root = new TreeNode(p2->next->val);
	ListNode* newHead = p2->next;
	p2->next = NULL;
	TreeNode* _left = sortedListToBST(head);
	TreeNode* _right = sortedListToBST(newHead->next);
	_root->left = _left;
	_root->right = _right;
	return _root;
}
