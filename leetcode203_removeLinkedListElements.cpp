#include "include.h"

/*
Remove all elements from a linked list of integers that have value val.

Example:
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

*/

ListNode* removeElements(ListNode* head, int val)
{
	if (head == NULL)return head;
	ListNode* resNode(NULL);
	ListNode* lastNode(NULL);
	while (head != NULL)
	{
		if (head->val != val)
		{
			if (resNode == NULL)
			{
				lastNode = head;
				resNode = head;
			}
			else
			{
				lastNode->next = head;
				lastNode = head;
			}
		}
		head = head->next;
	}
	if (lastNode != NULL)lastNode->next = NULL;
	return resNode;
}