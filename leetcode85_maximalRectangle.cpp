#include "include.h"
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:
Input:
[
	["1","0","1","0","0"],
	["1","0","1","1","1"],
	["1","1","1","1","1"],
	["1","0","0","1","0"]
]
Output: 6
*/
int maximalRectangle(vector<vector<char>>& matrix)
{
	if (matrix.empty() || matrix[0].empty()) return 0;
	int maxArea = 0;
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int>h(n, 0);
	for (int i = 0; i < m; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (matrix[i][j] == '1') 
			{
				h[j]++;
			}
			else h[j] = 0;
			int height = h[j];
			for (int k = j - 1; k >= 0; k--) 
			{
				if (h[k] == 0) break;
				height = min(height, h[k]);
				int width = j - k + 1;
				maxArea = max(maxArea, width*height);
			}
			maxArea = max(maxArea, h[j]);
		}
	}
	return maxArea;
}


