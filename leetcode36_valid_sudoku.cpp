#include "include.h"
/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


*/
bool isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; ++i)
	{
		set<char>help_row_set;
		set<char>help_coll_set;
		set<char>help_cell_set;
		int row_count = 0;
		int coll_count = 0;
		int cell_count = 0;
		for (int j = 0; j < 9; ++j)
		{
			//判断是否存在行重复
			if (board[i][j] != '.')
			{
				help_row_set.insert(board[i][j]);
				++row_count;
			}
			//判断是否存在列重复
			if (board[j][i] != '.')
			{
				help_coll_set.insert(board[j][i]);
				++coll_count;
			}
			//判断是否存在单元格重复
			int row_index = 3 * (i / 3);
			int coll_index = 3 * (i % 3);
			if (board[row_index + j / 3][coll_index + j % 3] != '.')
			{
				help_cell_set.insert(board[row_index + j / 3][coll_index + j % 3]);
				++cell_count;
			}
		}
		if (help_row_set.size() != row_count)	return false;
		if (help_coll_set.size() != coll_count)	return false;
		if (help_cell_set.size() != cell_count)	return false;
	}
	return true;
}




