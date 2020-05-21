#include "include.h"
/*
implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

*/


struct TrieNode
{
	int       m_count;
	TrieNode* m_children[26];
	TrieNode()
	{
		m_count = 0;
		for (int i = 0; i<26; ++i)
		{
			m_children[i] = NULL;
		}
	}
};
class Trie {
public:
private:
	TrieNode* m_root;
public:
	/** Initialize your data structure here. */
	Trie()
	{
		m_root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word)
	{
		TrieNode* root = m_root;
		for (int i = 0; i<word.length(); ++i)
		{
			char c = word[i];
			int index = c - 'a';
			if (root->m_children[index] == NULL)
			{
				root->m_children[index] = new TrieNode();
			}
			root->m_children[index]->m_count++;
			root = root->m_children[index];
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		TrieNode* root = m_root;
		for (int i = 0; i<word.length(); ++i)
		{
			if (root == NULL)
				return false;
			char c = word[i];
			int index = c - 'a';
			if (root->m_children[index] == NULL)
				return false;
			root = root->m_children[index];
		}
		int count = 0;
		for (int i = 0; i<26; ++i)
		{
			if (root->m_children[i] != NULL)
				count += root->m_children[i]->m_count;
		}
		return root->m_count>count;
	}
	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		TrieNode* root = m_root;
		for (int i = 0; i<prefix.length(); ++i)
		{
			if (root == NULL)
				return false;
			char c = prefix[i];
			int index = c - 'a';
			if (root->m_children[index] == NULL)
				return false;
			root = root->m_children[index];
		}
		return true;
	}
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/