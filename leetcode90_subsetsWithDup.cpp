#include "include.h"
void dfs(const vector<int>&nums,vector<int>&partition_solution, vector<vector<int>>&solutions)
{
	solutions.push_back(partition_solution);
	if (partition_solution.size() == nums.size())
	{
		return;
	}
	set<int>candidates;
	set_difference(nums.begin(), nums.end(), partition_solution.begin(), partition_solution.end(), inserter(candidates, candidates.begin()));
	vector<int>ccandidates;
	int max_val = partition_solution.empty() ? INT_MIN : partition_solution.back();
	copy_if(candidates.begin(), candidates.end(), back_inserter(ccandidates), [max_val](int num){return num >= max_val; });
	for (auto num:ccandidates)
	{
		partition_solution.push_back(num);
		dfs(nums, partition_solution, solutions);
		partition_solution.pop_back();
	}
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	vector<vector<int>>res_vvec;
	if (nums.empty())return res_vvec;
	sort(nums.begin(), nums.end());
	vector<int>partition_solution;
	dfs(nums, partition_solution, res_vvec);
	return res_vvec;
}