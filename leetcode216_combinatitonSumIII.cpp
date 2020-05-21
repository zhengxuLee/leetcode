#include "include.h"
void dfs3(int depth, int k, int n, vector<int>&parttition, vector<vector<int>>&res)
{
	int sum = accumulate(parttition.begin(), parttition.end(), (int)0);
	if (depth == k && sum == n)
	{
		res.push_back(parttition);
		return;
	}
	vector<int>candidates;
	int upper = min(9, n - sum - (k - depth - 1) * 1);
	int lower = max(1, n - sum - (k - depth - 1) * 9);
	int max1 = parttition.empty() ? 0 : parttition.back();
	lower = max(lower, max1 + 1);
	while (lower <= upper)
	{
		candidates.push_back(lower);
		lower++;
	}
	for (auto num : candidates)
	{
		parttition.push_back(num);
		dfs3(depth + 1, k, n, parttition, res);
		parttition.pop_back();
	}
	return;
}
vector<vector<int>> combinationSum3(int k, int n)
{
	vector<int>parttition;
	vector<vector<int>>res;
	dfs3(0, k, n, parttition, res);
	return res;
}