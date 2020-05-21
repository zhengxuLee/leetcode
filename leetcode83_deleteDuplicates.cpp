#include "include.h"


ListNode* deleteDuplicates(ListNode* head) 
{
	if (head==NULL)return NULL;
	ListNode* res_node(head);
	ListNode* p1(head);
	while (p1!=NULL)
	{
		if (p1->val != head->val)
		{
			head->next = p1;
			head = p1;
		}
		p1 = p1->next;
	}
	head->next = NULL;
	return res_node;
}