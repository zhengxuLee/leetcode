#include "include.h"


bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	if (matrix.empty())return false;
	if (matrix[0].empty())return false;
	if (target < matrix[0][0])return false;
	if (target>matrix.back().back())return false;
	for (int i = 0; i < matrix.size(); ++i)
	{
		if (matrix[i][0] == target)return true;
		else if (matrix[i].size()>1 && target<matrix[i][1])
		{
			return false;
		}
		else if ((matrix[i].size()>1 && target >= matrix[i][1]) && (i == matrix.size()-1 || target < matrix[i + 1][0]))
		{
			return binary_search(matrix[i].begin() + 1, matrix[i].end(), target);
		}
	}
	return false;
}