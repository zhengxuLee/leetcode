#include "include.h"
void dfs(vector<vector<char>>& board,int row,int coll,vector<vector<int>>&visited, vector<pair<int, int>>&solution)
{
	if (row<0 || row>=board.size() ||coll<0 ||coll>=board[0].size())return;
	if (board[row][coll]=='X')
	{
		visited[row][coll] = 1;
		return;
	}
	visited[row][coll] = 1;
	solution.push_back(make_pair(row, coll));
	if (row - 1 >= 0 && visited[row - 1][coll] != 1)
	{
		dfs(board, row - 1, coll, visited, solution);
	}
	if (coll + 1 < board[0].size() && visited[row][coll + 1] != 1)
	{
		dfs(board, row, coll + 1, visited, solution);
	}
	if (row + 1 < board.size() && visited[row + 1][coll] != 1)
	{
		dfs(board, row + 1, coll, visited, solution);
	}	
	if (coll - 1 >= 0 && visited[row][coll - 1] != 1)
	{
		dfs(board, row, coll - 1, visited, solution);
	}
		
}
void solve(vector<vector<char>>& board) 
{
	if (board.empty())return;
	vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[i].size(); ++j)
		{
			vector<pair<int, int>>solution;
			if (visited[i][j] != 1)
			{
				dfs(board, i, j, visited, solution);
			}
			for (auto pos : solution)
			{
				if (pos.first == 0 || pos.first == board.size() - 1 || pos.second == 0 || pos.second == board[0].size() - 1)
				{
					solution.clear();
					break;
				}
			}
			for (auto pos : solution)
			{
				board[pos.first][pos.second] = 'X';
			}
		}
	}
}
