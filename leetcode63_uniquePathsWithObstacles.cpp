#include "include.h"

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	vector<vector<int>> dp_map(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
	for (int i = 0; i < obstacleGrid[0].size(); ++i)
	{
		if (obstacleGrid[0][i]==0)
		{
			dp_map[0][i] = 1;
		}
		else
			break;
	}
	for (int j = 0; j < obstacleGrid.size(); ++j)
	{
		if (obstacleGrid[j][0] == 0)
		{
			dp_map[j][0] = 1;
		}
		else
			break;
	}
	for (int i = 1; i < obstacleGrid.size(); ++i)
	{
		for (int j = 1; j < obstacleGrid[0].size(); ++j)
		{
			int left = obstacleGrid[i][j - 1] == 0 ? dp_map[i][j - 1] : 0;
			int upper = obstacleGrid[i - 1][j] == 0 ? dp_map[i - 1][j] : 0;
			dp_map[i][j] = obstacleGrid[i][j]==1?0: left + upper;
		}
	}
	return dp_map.back().back();
}