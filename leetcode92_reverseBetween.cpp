#include "include.h"
#include <stack>
/*
�������ⶼ������
��һ����ά��һ��ָ�룬ָ��������е����һ��Ԫ��
�ڶ�����ά��һ��ָ�룬ָ���ѱ��������βԪ��
*/
ListNode* reverseBetween(ListNode* head, int m, int n)
{
	if (head == NULL)return NULL;
	ListNode* res_node = NULL;
	int count = 1;
	ListNode* last = NULL;
	while (count<m)
	{
		if (res_node==NULL)
		{
			res_node = head;
		}
		if (count==m-1)
		{
			last = head;
		}
		head = head->next;
		++count;
	}
	stack<ListNode*>myStack;
	while (count<=m)
	{
		myStack.push(head);
		head = head->next;
		++count;
	}
	while (!myStack.empty())
	{
		ListNode* top = myStack.top();
		myStack.pop();
		if (res_node==NULL)
		{
			res_node = top;
			last = top;
		}
		else
		{
			last->next = top;
			last = top;
		}
	}
	while (head!=NULL)
	{
		last->next = head;
		last = head;
		head = head->next;
	}
	last->next = NULL;
	return res_node;
}

