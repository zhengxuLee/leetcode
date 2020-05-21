#include "include.h"
/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
	[1,2,3],
	[1,3,2],
	[2,1,3],
	[2,3,1],
	[3,1,2],
	[3,2,1]
]


*/
void dfs(vector<int>&nums, vector<int>&partion_solution,vector<vector<int>>&solutions)
{
	if (partion_solution .size()== nums.size())
	{
		solutions.push_back(partion_solution);
		return;
	}
	vector<int>difference;
	//sort(partion_solution.begin(), partion_solution.end());这里不能直接排序，会改变部分解的状态
	vector<int>candidates;
	for (auto num : nums)
	{
		if (find(partion_solution.begin(),partion_solution.end(),num)==partion_solution.end())
		{
			candidates.push_back(num);
		}
	}
	for (auto num : candidates)
	{
		partion_solution.push_back(num);
		dfs(nums, partion_solution, solutions);
		partion_solution.pop_back();
	}
}
vector<vector<int>> permute(vector<int>& nums) 
{
	vector<int>partion_solution;
	vector<vector<int>>solutions;
	dfs(nums, partion_solution, solutions);
	return solutions;
}

