#include "include.h"

int minPathSum(vector<vector<int>>& grid) 
{
	if (grid.empty())return 0;
	vector<vector<int>> dp_map(grid.size(), vector<int>(grid[0].size(), 0));
	dp_map[0][0] = grid[0][0];
	for (int i = 1; i < grid[0].size();++i)
	{
		dp_map[0][i] = dp_map[0][i - 1] + grid[0][i];
	}
	for (int j = 1; j < grid.size(); ++j)
	{
		dp_map[j][0] = dp_map[j-1][0] + grid[j][0];
	}
	for (int i = 1; i < grid.size();++i)
	{
		for (int j = 1; j < grid[0].size();++j)
		{
			dp_map[i][j] = min(dp_map[i][j - 1], dp_map[i - 1][j]) + grid[i][j];
		}
	}
	return dp_map.back().back();
}