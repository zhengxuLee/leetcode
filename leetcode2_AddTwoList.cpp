#include "include.h"
/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)return l2;
	if (l2 == NULL)return l1;
	ListNode* resNode(NULL);
	ListNode* lastNode(NULL);
	int carry = 0;
	while (l1 != NULL || l2 != NULL)
	{
		int x = l1 != NULL ? l1->val : 0;
		int y = l2 != NULL ? l2->val : 0;
		if (resNode == NULL)
		{
			resNode = new ListNode((x + y + carry) % 10);
			lastNode = resNode;
		}
		else
		{
			ListNode* tmp = new ListNode((x + y + carry) % 10);
			lastNode->next = tmp;
			lastNode = tmp;
		}
		carry = (x + y + carry) / 10;
		if (l1 != NULL)l1 = l1->next;
		if (l2 != NULL)l2 = l2->next;
	}
	if (carry > 0)
	{
		ListNode* tmp = new ListNode(carry);
		lastNode->next = tmp;
	}
	return resNode;

}