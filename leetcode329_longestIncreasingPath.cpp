#include "include.h"
/*
Given an integer matrix, find the length of the longest increasing path.
From each cell, you can either move to four directions: left, right, up or down. 
You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:
Input: nums =
[
	[9,9,4],
	[6,6,8],
	[2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:
Input: nums =
[
	[3,4,5],
	[3,2,6],
	[2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

//--------------------------------------------以下为DFS的通解--------------------------------------------
struct Position
{
	int x;
	int y;
	Position(int _x, int _y) :x(_x), y(_y){};
	bool operator==(const Position& rhs)
	{
		return x == rhs.x && y == rhs.y;
	}
};
void dfs(const vector<vector<int>>& matrix, vector<Position>&partition_path,vector<vector<int>>&visited, int &maxLength)
{
	vector<Position>candidates;
	if (partition_path.empty())
	{
		for (int i = 0; i < matrix.size();++i)
		{
			for (int j = 0; j < matrix[0].size();++j)
			{
				candidates.push_back(Position(i, j));
			}
		}
	}
	else
	{
		Position current = partition_path.back();
		if (current.x - 1 >= 0 && matrix[current.x][current.y]<matrix[current.x - 1][current.y])
		{
			Position next(current.x - 1, current.y);
			if (visited[next.x][next.y]==0)
			{
				candidates.push_back(next);
			}
		}
		if (current.y + 1<matrix[0].size() && matrix[current.x][current.y]<matrix[current.x][current.y+1])
		{
			Position next(current.x, current.y+1);
			if (visited[next.x][next.y] == 0)
			{
				candidates.push_back(next);
			}
		}
		if (current.x + 1<matrix.size() && matrix[current.x][current.y]<matrix[current.x+1][current.y])
		{
			Position next(current.x+1, current.y);
			if (visited[next.x][next.y] == 0)
			{
				candidates.push_back(next);
			}
		}
		if (current.y - 1 >= 0 && matrix[current.x][current.y]<matrix[current.x][current.y-1])
		{
			Position next(current.x, current.y-1);
			if (visited[next.x][next.y] == 0)
			{
				candidates.push_back(next);
			}
		}
	}
	if (candidates.empty())
	{
		maxLength = max(maxLength, (int)partition_path.size());
		return;
	}
	for (auto next:candidates)
	{
		partition_path.push_back(next);
		visited[next.x][next.y] = 1;
		dfs(matrix, partition_path,visited, maxLength);
		visited[next.x][next.y] = 0;
		partition_path.pop_back();
	}
}
int longestIncreasingPath(vector<vector<int>>& matrix) 
{
	if (matrix.empty())return 0;
	int maxLength = 0;
	vector<Position>partition_path;
	vector<vector<int>>visited(matrix.size(), vector<int>(matrix[0].size(), 0));
	dfs(matrix, partition_path,visited, maxLength);
	return maxLength;
}

//--------------------------以下为动态规划的解法-----------------------
//int dfs(const vector<vector<int>>& matrix,vector<vector<int>>&cache, int currentX, int currentY)
//{
//	if (cache[currentX][currentY] != 0)
//	{
//		return cache[currentX][currentY];
//	}
//	int res = 1;
//	if (currentX - 1 >= 0 && matrix[currentX][currentY]<matrix[currentX-1][currentY])
//	{
//		res = max(res, 1 + dfs(matrix, cache, currentX - 1, currentY));
//	}
//	if (currentY+1<matrix[0].size() && matrix[currentX][currentY]<matrix[currentX][currentY+1])
//	{
//		res = max(res, 1 + dfs(matrix, cache, currentX, currentY + 1));
//	}
//	if (currentX + 1<matrix.size() && matrix[currentX][currentY]<matrix[currentX+1][currentY])
//	{
//		res = max(res, 1 + dfs(matrix, cache, currentX+1, currentY));
//	}
//	if (currentY - 1 >= 0 && matrix[currentX][currentY]<matrix[currentX][currentY-1])
//	{
//		res = max(res, 1 + dfs(matrix, cache, currentX, currentY - 1));
//	}
//	cache[currentX][currentY] = res;
//	return res;
//}
//int longestIncreasingPath(vector<vector<int>>& matrix)
//{
//	if (matrix.empty())return 0;
//	int res = 0;
//	vector<vector<int>>cache(matrix.size(), vector<int>(matrix[0].size(), 0));
//	for (int i = 0; i < matrix.size();++i)
//	{
//		for (int j = 0; j < matrix[0].size();++j)
//		{
//			res = max(res, dfs(matrix, cache, i, j));
//		}
//	}
//	return res;
//}



