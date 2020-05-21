#include "include.h"
#include <unordered_set>

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};


UndirectedGraphNode *cloneGraph_BFS(UndirectedGraphNode *node)
{
	if (node == NULL)return NULL;
	set<UndirectedGraphNode*>discovered_set;
	queue<UndirectedGraphNode*>myQueue;
	myQueue.push(node);
	discovered_set.insert(node);
	unordered_map < UndirectedGraphNode*, UndirectedGraphNode*>copied;
	UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
	copied[node] = newNode;
	while (!myQueue.empty())
	{
		int size = myQueue.size();
		for (int i = 0; i < myQueue.size();++i)
		{
			UndirectedGraphNode* front = myQueue.front();
			UndirectedGraphNode* copied_node = copied[front];
			myQueue.pop();
			for (auto neighbor:front->neighbors)
			{
				if (discovered_set.find(neighbor)==discovered_set.end())
				{
					myQueue.push(neighbor);
					discovered_set.insert(neighbor);
				}
				if (copied.find(neighbor)==copied.end())
				{
					UndirectedGraphNode* newNode = new UndirectedGraphNode(neighbor->label);
					copied[neighbor] = newNode;
				}
				copied_node->neighbors.push_back(copied[neighbor]);
			}
		}
	}
	return newNode;
}


UndirectedGraphNode *cloneGraph_DFS(UndirectedGraphNode *node)
{
	if (node == NULL)return NULL;
	stack<UndirectedGraphNode*>myStack;
	unordered_set<UndirectedGraphNode*>discovered_set;
	myStack.push(node);
	discovered_set.insert(node);
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>node_copiedNode;
	UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
	node_copiedNode[node] = new_node;
	while (!myStack.empty())
	{
		UndirectedGraphNode* top = myStack.top();
		myStack.pop();
		UndirectedGraphNode* copiedNode = node_copiedNode[top];
		for (auto neighbor:top->neighbors)
		{
			if (discovered_set.find(neighbor)==discovered_set.end())
			{
				myStack.push(neighbor);
				discovered_set.insert(neighbor);
			}
			if (node_copiedNode.find(neighbor)==node_copiedNode.end())
			{
				UndirectedGraphNode* node = new UndirectedGraphNode(neighbor->label);
				node_copiedNode[neighbor] = node;
			}
			copiedNode->neighbors.push_back(node_copiedNode[neighbor]);
		}
	}
	return new_node;
}

void dfs(UndirectedGraphNode* current, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>&node_newNode)
{
	if (node_newNode.find(current)!=node_newNode.end())return;
	UndirectedGraphNode* new_node = new UndirectedGraphNode(current->label);
	node_newNode[current] = new_node;
	for (auto neighbor:current->neighbors)
	{
		dfs(neighbor, node_newNode);
		node_newNode[current]->neighbors.push_back(node_newNode[neighbor]);
	}
}
UndirectedGraphNode *cloneGraph_DFS_R(UndirectedGraphNode *node)
{
	if (node == NULL)return NULL;
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>node_newNode;
	dfs(node, node_newNode);
	return node_newNode[node];
}

