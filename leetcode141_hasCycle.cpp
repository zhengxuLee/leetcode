#include "include.h"

bool hasCycle(ListNode *head) 
{
	if (head == NULL)return false;
	ListNode* faster = head;
	ListNode* slower = head;
	while (faster!=NULL && faster->next!=NULL)
	{
		faster = faster->next->next;
		slower = slower->next;
		if (faster==slower)
		{
			return true;
		}
	}
	return false;
}