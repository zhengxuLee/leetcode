#include "include.h"
ListNode* merge(ListNode* list1, ListNode* list2)
{
	if (list1 == NULL)return list2;
	if (list2 == NULL)return list1;
	ListNode* firstNode(NULL);
	ListNode* lastNode(NULL);
	while (list1!=NULL && list2!=NULL)
	{
		if (list1->val<=list2->val)
		{
			if (firstNode == NULL)firstNode = list1;
			if (lastNode == NULL)lastNode = list1;
			else
			{
				lastNode->next = list1;
				lastNode = list1;
			}
			list1 = list1->next;
		}
		else
		{
			if (firstNode == NULL)firstNode = list2;
			if (lastNode == NULL)lastNode = list2;
			else
			{
				lastNode->next = list2;
				lastNode = list2;
			}
			list2 = list2->next;
		}
	}
	ListNode* rest = list1 == NULL ? list2 : list1;
	while (rest!=NULL)
	{
		lastNode->next = rest;
		lastNode = rest;
		rest = rest->next;
	}
	return firstNode;
}
ListNode* sortList(ListNode* head) 
{
	if (head == NULL)return NULL;
	if (head->next == NULL)return head;
	int length = 0;
	ListNode* p1(head);
	while (p1!=NULL)
	{
		p1 = p1->next;
		++length;
	}
	ListNode* divide(head);
	for (int i = 0; i < length / 2-1;++i)
	{
		divide = divide->next;
	}
	ListNode* newStart = divide->next;
	divide->next = NULL;
	ListNode* list1 = sortList(head);
	ListNode* list2 = sortList(newStart);
	ListNode* res_node = merge(list1, list2);
	return res_node;
}