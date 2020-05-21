#include "include.h"
//void setZeroes(vector<vector<int>>& matrix) 
//{
//	if (matrix.empty())return;
//	set<int>row_indexs;
//	set<int>coll_index;
//	for (int i = 0; i < matrix.size();++i)
//	{
//		for (int j = 0; j < matrix[i].size();++j)
//		{
//			if (matrix[i][j]==0)
//			{
//				row_indexs.insert(i);
//				coll_index.insert(j);
//			}
//		}
//	}
//	for (auto row : row_indexs)
//	{
//		fill(matrix[row].begin(), matrix[row].end(), 0);
//	}
//	for (int i = 0; i < matrix.size(); ++i)
//	{
//		for (auto coll : coll_index)
//		{
//			matrix[i][coll] = 0;
//		}
//	}
//	return;
//}

void setZeroes(vector<vector<int>>& matrix)
{
	if (matrix.empty())return;
	vector<int>row_indexs(matrix.size(), 0);
	vector<int>coll_index(matrix[0].size(), 0);
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			if (matrix[i][j] == 0)
			{
				row_indexs[i] = 1;
				coll_index[j] = 1;
			}
		}
	}
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			if (row_indexs[i]==1||coll_index[j]==1)
			{
				matrix[i][j] = 0;
			}
		}
	}
	
	return;
}