#include "include.h"
/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:
Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you should
also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

bool canFinish1(int numCourses, vector<pair<int, int>>& prerequisites)
{
	if (numCourses < 0)return false;
	if (prerequisites.empty())return true;
	vector<int>courseIncome(numCourses, 0);
	vector<vector<int>>relation(numCourses);
	for (auto pair : prerequisites)
	{
		courseIncome[pair.second]++;
		relation[pair.first].push_back(pair.second);
	}
	//每一轮里面找到一个为0的，如果有一轮找不到，必然有环
	for(int i = 0; i < numCourses; i++) 
	{
		int j = 0;
		for (; j < numCourses; j++)
		{
			if (courseIncome[j] == 0)
				break;
			if (j == numCourses) return false;
		}
		courseIncome[j] = -1;
		for (int neigh : relation[j])
			courseIncome[neigh]--;
	}
	return true;
}

bool hasCycle(int start, const vector<vector<int>>&relation, vector<int>&onPath, vector<int>&courseStatus)
{
	if (courseStatus[start] != 0)
		return false;
	courseStatus[start] = 1;
	onPath[start] = 1;
	vector<int>nexts = relation[start];
	for (int i = 0; i < nexts.size(); ++i)
	{
		int neighbor = nexts[i];
		if (onPath[neighbor]==1)
			return true;
		if (hasCycle(neighbor, relation, onPath, courseStatus))
			return true;
	}
	onPath[start] = 0;
	return false;
}
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
{
	if (numCourses < 0)return false;
	if (prerequisites.empty())return true;
	vector<vector<int>>relation(numCourses);
	for (auto &pair : prerequisites)
	{
		relation[pair.first].push_back(pair.second);
	}
	vector<int>courseStatus(numCourses, 0);
	vector<int>onPath(numCourses, 0);
	for (int i = 0; i < numCourses; ++i)
	{
		if (hasCycle(i, relation, onPath, courseStatus))
		{
			return false;
		}
	}
	return true;
}