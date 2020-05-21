#include "include.h"
/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
[1, 2, 3, 4],
[5, 6, 7, 8],
[9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


*/
void helper(vector<vector<int>>& matrix, int start[2], int end[2], vector<int>&loop_vec)
{
	if (start[0]>end[0] || start[1]>end[1])
	{
		return;
	}
	for (int j = start[1]; j<= end[1]; ++j)
	{
		loop_vec.push_back(matrix[start[0]][j]);
	}
	for (int i = start[0] + 1; i < end[0];++i)
	{
		loop_vec.push_back(matrix[i][end[1]]);
	}
	//当输入区域在同一行或同一列时，不应往返导致重复
	if (start[0]!=end[0])
	{
		for (int j = end[1]; j >= start[1]; --j)
		{
			loop_vec.push_back(matrix[end[0]][j]);
		}
	}
	if (start[1]!=end[1])
	{
		for (int i = end[0] - 1; i>start[0]; --i)
		{
			loop_vec.push_back(matrix[i][start[1]]);
		}
	}
	return;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
	vector<int>res_vec; 
	if (matrix.empty())
	{
		return res_vec;
	}
	int row = matrix.size();
	int coll = matrix[0].size();
	int start[2] = { 0, 0 };
	int end[2] = { row - 1, coll - 1 };
	while (start[0]<=end[0] && start[1]<=end[1])
	{
		helper(matrix, start, end, res_vec);
		++start[0];
		++start[1];
		--end[0];
		--end[1];
	}
	return res_vec;
}
