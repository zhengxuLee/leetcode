#include "include.h"
void dfs(int k, int n, int selected_max, vector<int>&partition_solution, vector<vector<int>>&solutions)
{
	if (partition_solution.size() == k || n - selected_max < k - partition_solution.size())
	{
		if (partition_solution.size() == k)solutions.push_back(partition_solution);
		return;
	}
	vector<int>candidates;
	for (int i = selected_max + 1; i <= n; ++i)
	{
		candidates.push_back(i);
	}
	for (auto num : candidates)
	{
		partition_solution.push_back(num);
		dfs(k, n, num, partition_solution, solutions);
		partition_solution.pop_back();
	}
}

vector<vector<int>> combine(int n, int k)
{
	vector<int>partition_solution;
	vector<vector<int>>solutions;
	dfs(k, n, 0, partition_solution, solutions);
	return solutions;
}