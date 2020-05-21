#include "include.h"
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.
A sudoku solution must satisfy all of the following rules:
Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

A sudoku puzzle...
...and its solution numbers marked in red.
*/
bool solved = false;
void dfs(vector<vector<char>> &soluion,int i,int j)
{
	if (i == 9)
	{
		solved = true;
		return;
	}
	if (j == 9)
	{
		dfs(soluion, i + 1, 0);
		return;
	}
	if (soluion[i][j] != '.')
	{
		dfs(soluion, i, j + 1);
		return;
	}
	set<char>occur;//i，j的同行，同列，同单元格中已经出现的字符，set去重
	for (int l = 0; l < 9;++l)
	{
		if (soluion[i][l] != '.')
			occur.insert(soluion[i][l]);
		if (soluion[l][j] != '.')
			occur.insert(soluion[l][j]);
		if(soluion[i - i % 3 + l / 3][j - j % 3 + l % 3] != '.')
			occur.insert(soluion[i - i % 3 + l / 3][j - j % 3 + l % 3]);
	}
	vector<char>candidates;
	for (char a = '1'; a <= '9';++a)
	{
		if (occur.find(a)==occur.end())
			candidates.push_back(a);
	}
	if (candidates.empty())return;
	for (auto c:candidates)
	{
		
		soluion[i][j] = c;
		dfs(soluion, i, j + 1);
		if (solved)return;//找到之后直接返回，不然结果会被重写
		soluion[i][j] = '.';
	}
}
void solveSudoku(vector<vector<char>>& board) 
{
	dfs(board, 0, 0);
}


