#include "include.h"

void fullfill_matrix(int &initial, int start[2], int end[2], vector<vector<int>>& matrix)
{
	if (start[0] > end[0] || start[1] > end[1])
	{
		return;
	}
	for (int j = start[1]; j <= end[1]; ++j)
	{
		matrix[start[0]][j] = initial;
		++initial;
	}
	for (int i = start[0] + 1; i < end[0]; ++i)
	{
		matrix[i][end[1]] = initial;
		++initial;
	}
	if (start[0] < end[0])
	{
		for (int j = end[1]; j >= start[1]; --j)
		{
			matrix[end[0]][j] = initial;
			++initial;
		}
	}
	if (start[1]<end[1])
	{
		for (int i = end[0] - 1; i > start[0]; --i)
		{
			matrix[i][start[1]] = initial;
			++initial;
		}
	}
	return;
}
vector<vector<int>> generateMatrix(int n)
{
	int start[2] = { 0, 0 };
	int end[2] = { n - 1, n - 1 };
	vector<vector<int>>matrix;
	for (int i = 0; i < n; ++i)
	{
		vector<int>row;
		for (int j = 0; j < n; ++j)
		{
			row.push_back(0);
		}
		matrix.push_back(row);
	}
	int initial = 1;
	while (start[0] <= end[0] && start[1] <= end[1])
	{
		fullfill_matrix(initial, start, end, matrix);
		++start[0];
		++start[1];
		--end[0];
		--end[1];
	}
	return matrix;
}