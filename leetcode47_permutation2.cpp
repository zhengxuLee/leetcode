#include "include.h"
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
	[1,1,2],
	[1,2,1],
	[2,1,1]
]


*/
void dfsUnique(vector<int>&nums, vector<int>&partion_solution, vector<vector<int>>&solutions)
{
	if (partion_solution.size() == nums.size())
	{
		solutions.push_back(partion_solution);
		return;
	}
	set<int>candidates;
	map<int, int>count;
	for (auto num:nums)count[num] = 0;
	for (auto num : nums)count[num]++;
	for (auto num : partion_solution)count[num]--;
	for (auto pair:count)
	{
		if (pair.second!=0)
		{
			candidates.insert(pair.first);
		}
	}
	for (auto num:candidates)
	{
		partion_solution.push_back(num);
		dfsUnique(nums, partion_solution, solutions);
		partion_solution.pop_back();
	}
}

vector<vector<int>> permuteUnique(vector<int>& nums) 
{
	vector<int>partion_solution;
	vector<vector<int>>solutions;
	sort(nums.begin(), nums.end());
	dfsUnique(nums, partion_solution, solutions);
	return solutions;
}

