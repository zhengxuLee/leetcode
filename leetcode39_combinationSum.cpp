#include "include.h"
/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
[7],
[2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
[2,2,2,2],
[2,3,3],
[3,5]
]

*/
void helper(vector<int> & cands, int idx, int target, vector<int> & combo, vector<vector<int>>& ans)
{
	if (target < 0) return;
	if (target == 0) ans.push_back(combo);
	for (int i = idx; i < cands.size(); ++i)
	{
		combo.push_back(cands[i]);
		helper(cands, i, target - cands[i], combo, ans);
		combo.pop_back();
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
	vector<vector<int>> ans;
	vector<int> combo;
	helper(candidates, 0, target, combo, ans);
	return ans;
}


