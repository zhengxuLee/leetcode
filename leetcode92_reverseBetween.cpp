#include "include.h"
#include <stack>
/*
这类问题都是类似
第一个是维护一个指针，指向输出序列的最后一个元素
第二个是维护一个指针，指向已遍历区间的尾元素
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

