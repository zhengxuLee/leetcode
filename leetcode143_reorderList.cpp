#include "include.h"
void reorderList(ListNode* head)
{
	if (head == NULL || head->next == NULL)return;
	ListNode* s1 = head;
	ListNode* s2 = head;
	while (s2 != NULL && s2->next != NULL)
	{
		s1 = s1->next;
		s2 = s2->next->next;
	}

	ListNode* prevNode(NULL);
	ListNode* current(s1);
	ListNode* nextNode(NULL);
	while (current != NULL)
	{
		nextNode = current->next;
		current->next = prevNode;
		prevNode = current;
		current = nextNode;
	}
	ListNode* p1 = head;
	ListNode* lastNode = NULL;
	while (p1 != s1 && prevNode != NULL)
	{
		if (lastNode == NULL)
		{
			lastNode = p1;
			p1 = p1->next;
			lastNode->next = prevNode;
			lastNode = prevNode;
			prevNode = prevNode->next;
		}
		else
		{
			lastNode->next = p1;
			lastNode = p1;
			p1 = p1->next;
			lastNode->next = prevNode;
			lastNode = prevNode;
			prevNode = prevNode->next;
		}
	}
}