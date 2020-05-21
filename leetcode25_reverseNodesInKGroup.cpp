#include "include.h"
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:
Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/


//方法一使用栈，空间开销大
//ListNode* reverseKGroup(ListNode* head, int k)
//{
//	if (head == NULL || k <= 0)return head;
//	stack<ListNode*>myStack;
//	int i = 0;
//	ListNode* p1 = head;
//	while (i < k && p1 != NULL)
//	{
//		myStack.push(p1);
//		p1 = p1->next;
//		++i;
//	}
//	if (i < k && p1 == NULL)return head;
//	ListNode* start(NULL);
//	ListNode* current(NULL);
//	while (!myStack.empty())
//	{
//		ListNode* top = myStack.top();
//		myStack.pop();
//		if (start == NULL)
//		{
//			start = top;
//			current = top;
//		}
//		else
//		{
//			current->next = top;
//			current = current->next;
//		}
//	}
//	ListNode* rest = reverseKGroup(p1, k);
//	current->next = rest;
//	return start;
//}

ListNode* reverseList(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* curr = head;
	while (curr != NULL)
	{
		ListNode* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}
ListNode* reverseKGroup(ListNode* head, int k)
{
	if (head == NULL || k <= 1)return head;
	int i = 0;
	ListNode* p1 = head;
	ListNode* last = NULL;
	while (i < k && p1 != NULL)
	{
		last = p1;
		p1 = p1->next;
		++i;
	}
	if (i < k && p1 == NULL)return head;
	last->next = NULL;
	ListNode* reverse = reverseList(head);
	ListNode* rest = reverseKGroup(p1, k);
	head->next = rest;
	return reverse;
}

