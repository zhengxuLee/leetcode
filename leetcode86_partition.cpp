#include "include.h"

ListNode* partition(ListNode* head, int x) 
{
	if (head == NULL)return NULL;
	ListNode* res_node = NULL;
	ListNode* p1 = NULL;
	ListNode* p2 = head;
	queue<ListNode*>wait_queue;
	while (p2 != NULL)
	{
		if (p2->val < x)
		{
			if (res_node == NULL)
			{
				res_node = p2;
				p1 = p2;
			}
			else
			{
				p1->next = p2;
				p1 = p2;
			}
		}
		else
		{
			wait_queue.push(p2);
		}
		p2 = p2->next;
	}
	while (!wait_queue.empty())
	{
		ListNode* _front = wait_queue.front();
		wait_queue.pop();
		if (p1 == NULL)
		{
			res_node = _front;
		}
		else
		{
			p1->next = _front;
		}
		p1 = _front;
	}
	p1->next = NULL;
	return res_node;
}