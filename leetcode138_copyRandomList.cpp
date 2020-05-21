#include "include.h"

// Definition for singly - linked list with a random pointer.
struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head)
{
	if (head == NULL)return NULL;
	unordered_map<RandomListNode*, RandomListNode*>node_copied_map;
	unordered_set<RandomListNode*>random_set = { head };
	RandomListNode* new_node = new RandomListNode(head->label);
	node_copied_map[head] = new_node;
	RandomListNode* last_node = new_node;
	head = head->next;
	while (head != NULL)
	{
		RandomListNode* node_tmp = new RandomListNode(head->label);
		node_copied_map[head] = node_tmp;
		last_node->next = node_tmp;
		last_node = node_tmp;
		if (node_copied_map.find(head->random) != node_copied_map.end())
			node_tmp->random = node_copied_map[head->random];
		else
			random_set.insert(head);
		head = head->next;
	}
	for (auto old:random_set)
	{
		node_copied_map[old]->random = node_copied_map[old->random];
	}
	return new_node;
}