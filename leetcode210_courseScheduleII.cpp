#include "include.h"
/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
course 0. So the correct course order is [0,1] .

Example 2:
Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

bool DFS(int start, const vector<vector<int>>&graph, vector<int>&status, vector<int>&topoSort)
{
	status[start] = 1;
	vector<int>nexts = graph[start];
	for (int i = 0; i < nexts.size(); ++i)
	{
		int next = nexts[i];
		if (status[next] == 1)//next node is discovered,loop detected!
		{
			topoSort.clear();
			return true;
		}
		if (status[next] == 0)//next node is undiscovered
		{
			if (DFS(next, graph, status, topoSort))
			{
				return true;
			}
		}
	}
	status[start] = 2;
	topoSort.push_back(start);
	return false;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
{
	vector<int>topoSort;
	if (numCourses < 0)return topoSort;
	vector<vector<int>>graph(numCourses);
	vector<int>status(numCourses, 0);//0-undiscovered,1-discovered,2-visited;
	for (auto pair : prerequisites)
	{
		graph[pair.first].push_back(pair.second);
	}
	for (int i = 0; i < numCourses; ++i)
	{
		if (status[i] == 0)
		{
			if (DFS(i, graph, status, topoSort))
			{
				topoSort.clear();
				return topoSort;
			}
		}
	}
	return topoSort;
}