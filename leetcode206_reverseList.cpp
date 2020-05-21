#include "include.h"
////单链表反转递归版
//ListNode* reverseList(ListNode* head) 
//{
//	if (head == NULL)return NULL;
//	if (head->next == NULL)return head;
//	ListNode* res_node = head;
//	while (res_node->next->next!=NULL)
//	{
//		res_node = res_node->next;
//	}
//	ListNode* next = res_node;
//	res_node = res_node->next;
//	next->next = NULL;
//	res_node->next = reverseList(head);
//	return res_node;
//}

//单链表反转迭代版
ListNode* reverseList1(ListNode* head)
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