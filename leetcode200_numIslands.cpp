#include "include.h"
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input:

11110
11010
11000
00000

Output: 1

Example 2:
Input:

11000
11000
00100
00011

Output: 3
*/
void dfs(const vector<vector<char>>& grid, vector<vector<int>>&visited, int i, int j)
{
	if (visited[i][j] == 1)return;
	if (grid[i][j] == '0')
	{
		visited[i][j] = 1;
		return;
	}
	visited[i][j] = 1;
	if (i - 1 >= 0)
		dfs(grid, visited, i - 1, j);
	if (j + 1 < grid[0].size())
		dfs(grid, visited, i, j + 1);
	if (i + 1 < grid.size())
		dfs(grid, visited, i + 1, j);
	if (j - 1 >= 0)
		dfs(grid, visited, i, j - 1);
}

int numIslands(vector<vector<char>>& grid)
{
	if (grid.empty())return 0;
	int islandNumber = 0;
	vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == '1' && visited[i][j] == 0)
			{
				dfs(grid, visited, i, j);
				++islandNumber;
			}
		}
	}
	return islandNumber;
}