#include "include.h"
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)return NULL;
	if (pHead->next == NULL)return pHead;
	ListNode* res(NULL);
	ListNode* last(NULL);
	while (pHead != NULL)
	{
		ListNode* p = pHead;
		int count = 0;
		while (p != NULL && p->val == pHead->val)
		{
			p = p->next;
			++count;
		}
		if (count == 1)
		{
			if (res == NULL)
			{
				res = pHead;
				last = pHead;
			}
			else
			{
				last->next = pHead;
				last = pHead;
			}
		}
		pHead = p;
	}
	last->next = NULL;
	return res;
}
