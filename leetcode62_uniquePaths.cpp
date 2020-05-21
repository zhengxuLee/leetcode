#include "include.h"

int uniquePaths(int m, int n) 
{
	vector<vector<int>>dp_map(n, vector<int>(m, 1));
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < m;++j)
		{
			dp_map[i][j] = dp_map[i][j - 1] + dp_map[i - 1][j];
		}
	}
	return dp_map[n-1][m-1];
}