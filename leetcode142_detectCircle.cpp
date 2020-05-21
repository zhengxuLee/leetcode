#include "include.h"

ListNode *detectCycle(ListNode *head) 
{
	if (head == NULL || head->next == NULL)return NULL;
	ListNode* lf = head;
	ListNode* lw = head;
	while (lf != NULL && lf->next != NULL)
	{
		lw = lw->next;
		lf = lf->next->next;
		if (lw == lf)break;
	}
	if (lw != lf)return NULL;
	lw = head;
	while (lw != lf)
	{
		lw = lw->next;
		lf = lf->next;
	}
	return lw;
}
