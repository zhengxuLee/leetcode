#include "include.h"
#include <unordered_set>
//--------------------以上是DFS的方法----------------
/*
int length = INT_MAX;
int count(string s1, string s2)
{
	int res = 0;
	for (int i = 0; i < s1.size(); ++i)
	{
		if (s1[i] != s2[i])++res;
	}
	return res;
}
void dfs(string beginWord, string endWord, vector<string>& wordList, vector<string>&partition_solution)
{
	if (length!=INT_MAX && partition_solution.size()>length)return;
	if (!partition_solution.empty() && partition_solution.back() == endWord)
	{
		length = min(length, (int)partition_solution.size());
		return;
	}
	string lastWord = partition_solution.empty() ? beginWord : partition_solution.back();
	vector<string>candidates;
	for (auto &str : wordList)
	{
		if (find(partition_solution.begin(), partition_solution.end(), str) == partition_solution.end())
		{
			if (count(lastWord, str) == 1)
			{
				candidates.push_back(str);
			}
		}
	}
	for (auto str1 : candidates)
	{
		partition_solution.push_back(str1);
		dfs(beginWord, endWord, wordList, partition_solution);
		partition_solution.pop_back();
	}

}
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	vector<string>partition_solution;
	dfs(beginWord, endWord, wordList, partition_solution);
	return length;
}
//--------------------以上是DFS的方法----------------
*/


//--------------------以下是BFS的方法----------------
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	queue<string>myQueue;
	myQueue.push(beginWord);
	unordered_set<string>left(wordList.begin(), wordList.end());
	left.erase(beginWord);
	int length = 0;
	while (!myQueue.empty())
	{
		int size = myQueue.size();
		for (int i = 0; i < size;++i)
		{
			string front = myQueue.front();
			myQueue.pop();
			if (front==endWord)return length + 1;
			for (int i = 0; i < front.size();++i)
			{
				for (int j = 0; j < 26; ++j)
				{
					string tmp(front);
					tmp[i] = 'a' + j;
					if (left.find(tmp) != left.end())
					{
						myQueue.push(tmp);
						left.erase(tmp);
					}
				}
			}
		}
		++length;
	}
	return 0;
}


