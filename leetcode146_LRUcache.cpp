#include "include.h"

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:
LRUCache cache = new LRUCache( 2 );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

/*
//----------------单链表，线性复杂度--------------------
class LRUCache {
public:
	list<int>ls;
	unordered_map<int, int>cache;
	int count;
	int capacity;
	LRUCache(int capacity1)
	{
		cache.clear();
		ls.clear();
		count = 0;
		capacity = capacity1;
	}

	int get(int key)
	{
		auto itr = cache.find(key);
		if (itr == cache.end())
		{
			return -1;
		}
		else
		{
			//move to head;
			ls.remove(key);
			ls.push_front(key);

			//return climet;
			return cache[key];
		}
	}

	void put(int key, int value)
	{
		auto itr = cache.find(key);
		if (itr == cache.end())
		{
			ls.push_front(key);
			cache[key] = value;
			++count;
			if (count > capacity)
			{
				int last = ls.back();
				ls.pop_back();
				cache.erase(last);
				--count;
			}
		}
		else
		{
			//move to head;
			ls.remove(key);
			ls.push_front(key);
			cache[key] = value;
		}
	}
};
*/


//----------------------双链表，常数复杂度--------------------------
struct DoubleLinkListNode
{
	int key;
	int value;
	DoubleLinkListNode* pre;
	DoubleLinkListNode* next;
};
class DoubleLinkList
{
private:
	DoubleLinkListNode* head;
	DoubleLinkListNode* tail;
public:
	DoubleLinkList()
	{
		head = new DoubleLinkListNode();
		tail = new DoubleLinkListNode();
		head->next = tail;
		tail->pre = head;
	}
	void addNode(DoubleLinkListNode* node)
	{
		node->pre = head;
		node->next = head->next;
		head->next->pre = node;
		head->next = node;
	}
	void removeNode(DoubleLinkListNode* node)
	{
		DoubleLinkListNode* preNode = node->pre;
		DoubleLinkListNode* nextNode = node->next;
		preNode->next = nextNode;
		nextNode->pre = preNode;
	}
	void moveToHead(DoubleLinkListNode* node)
	{
		removeNode(node);
		addNode(node);
	}
	DoubleLinkListNode* popTail()
	{
		DoubleLinkListNode* res = tail->pre;
		removeNode(res);
		return res;
	}
};
class LRUCache
{
public:
	unordered_map<int, DoubleLinkListNode*>cache;
	DoubleLinkList* ls;
	int count;
	int capacity;
	LRUCache(int capacity1)
	{
		cache.clear();
		count = 0;
		capacity = capacity1;
		ls = new DoubleLinkList();
	}
	int get(int key)
	{
		auto itr = cache.find(key);
		if (itr == cache.end())
		{
			return -1;
		}
		else
		{
			DoubleLinkListNode* node = itr->second;
			ls->moveToHead(node);
			return node->value;
		}
	}

	void put(int key, int value)
	{
		auto itr = cache.find(key);
		if (itr == cache.end())
		{
			DoubleLinkListNode* newNode = new DoubleLinkListNode();
			newNode->key = key;
			newNode->value = value;
			cache[key] = newNode;
			ls->addNode(newNode);
			++count;
			if (count > capacity)
			{
				DoubleLinkListNode* tail = ls->popTail();
				cache.erase(tail->key);
				--count;
			}
		}
		else
		{
			itr->second->value = value;
			ls->moveToHead(itr->second);
		}
	}
};