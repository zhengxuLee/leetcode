#include "include.h"

int minimumTotal(vector<vector<int>>& triangle) 
{
	if (triangle.empty())return 0;
	vector<vector<int>>minSum_dp;
	for (int i = 0; i < triangle.size();++i)
	{
		vector<int>row_position(triangle[i].size(), 0);
		minSum_dp.push_back(row_position);
	}
	minSum_dp[0][0] = triangle[0][0];
	for (int j = 1; j < triangle.size();++j)
	{
		for (int k = 0; k < minSum_dp[j].size();++k)
		{
			if (k == 0)
				minSum_dp[j][k] = minSum_dp[j - 1][0] + triangle[j][0];
			else if (k == minSum_dp[j].size() - 1)
				minSum_dp[j][k] = minSum_dp[j - 1].back() + triangle[j].back();
			else
				minSum_dp[j][k] = min(minSum_dp[j - 1][k - 1], minSum_dp[j - 1][k]) + triangle[j][k];
		}
	}
	return *min_element(minSum_dp.back().begin(), minSum_dp.back().end());
}