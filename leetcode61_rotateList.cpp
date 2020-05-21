#include "include.h"


class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) 
	{
		if (head==NULL || head->next==NULL)
		{
			return head;
		}
		ListNode* res_node(NULL);
		ListNode* head_bak(head);
		int length = 1;
		while (head->next!=NULL)
		{
			head = head->next;
			++length;
		}
		k = k%length;
		ListNode* split(head_bak);
		for (int i = 0; i<length-k-1;++i)
		{
			split = split->next;
		}
		if (split == NULL)
		{
			res_node = head_bak;
		}
		else
		{
			res_node = split->next;
			split->next = NULL;
			head->next = head_bak;
		}
		return res_node;
		
	}
};