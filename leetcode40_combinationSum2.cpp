#include "include.h"
/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
[1,2,2],
[5]
]

*/

void dfs(vector<int>& candidates, int target, int k, vector<int>&partion_solution, vector<vector<int>>&solution)
{
	//µÝ¹é»ù
	if (target < 0)return;
	if (target == 0)
	{
		solution.push_back(partion_solution);
		return;
	}
	for (int i = k; i < candidates.size() && candidates[i] <= target; ++i)
	{
		if (i > k  && candidates[i - 1] == candidates[i])continue;
		partion_solution.push_back(candidates[i]);
		dfs(candidates, target - candidates[i], i + 1, partion_solution, solution);
		partion_solution.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
{
	vector<vector<int>>solutions;
	sort(candidates.begin(), candidates.end());
	vector<int>partion_solution;
	dfs(candidates, target, 0, partion_solution, solutions);
	return solutions;
}
