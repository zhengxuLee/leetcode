#include "include.h"
void dfs(const vector<int>& nums, int k, vector<int>&partition_solution,vector<vector<int>>&solutions)
{
	solutions.push_back(partition_solution);
	if (k==nums.back())return;
	vector<int>candidates;
	copy_if(nums.begin(), nums.end(), back_inserter(candidates), [k](int num){return num > k; });
	for (auto num:candidates)
	{
		partition_solution.push_back(num);
		dfs(nums, num, partition_solution, solutions);
		partition_solution.pop_back();
	}
	return;
}
vector<vector<int>> subsets(vector<int>& nums) 
{
	vector<int>partition_solution;
	vector<vector<int>>solutions;
	dfs(nums, INT_MIN, partition_solution, solutions);
	return solutions;
}

