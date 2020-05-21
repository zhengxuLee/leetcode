#include "include.h"

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:
Input:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 
4
*/

int maximalSquare(vector<vector<char>>& matrix)
{
	int m = matrix.size();
	if (m == 0)return 0;
	int n = matrix[0].size();
	if (n == 0)return 0;
	vector<vector<int>>dp(m, vector<int>(n, 0));
	int maxLength = 0;
	for (int j = 0; j < n; ++j)
	{
		if (matrix[0][j] == '1')
		{
			dp[0][j] = 1;
			maxLength = 1;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		if (matrix[i][0] == '1')
		{
			dp[i][0] = 1;
			maxLength = 1;
		}
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (matrix[i][j] == '1')
			{
				dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
				maxLength = max(maxLength, dp[i][j]);
			}
		}
	}
	return maxLength*maxLength;
}