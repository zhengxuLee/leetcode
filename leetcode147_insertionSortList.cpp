#include "include.h"
//这是一种很巧妙的方法，指针太多，自己写的时候很难写出答案
ListNode* insertionSortList(ListNode* head) {
	if (head == NULL || head->next == NULL)return head;
	ListNode* lc = head;
	head = head->next;
	lc->next = NULL;
	while (head)
	{
		ListNode*t = lc;
		ListNode*prev = NULL;
		while (t && t != head && t->val < head->val)
		{
			prev = t;
			t = t->next;
		}
		ListNode*nx = head->next;
		//last
		if (t == NULL)
		{
			prev->next = head;
			head->next = NULL;
		}
		//first
		else if (t == lc)
		{
			head->next = lc;
			lc = head;
		}
		//middle
		else
		{
			prev->next = head;
			head->next = t;
		}
		head = nx;//=> head->next
	}
	return lc;
}