#include "include.h"

/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.

*/

int findTargetSumWays(vector<int>& nums, int S)
{
	if (nums.empty())return 0;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (S > sum || (S + sum) % 2 == 1)return 0;
	int target = (S + sum) / 2;
	vector<vector<int>>dp(nums.size() + 1, vector<int>(target + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= nums.size(); ++i)
	{
		for (int j = 0; j <= target; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= nums[i - 1])
			{
				dp[i][j] += dp[i - 1][j - nums[i - 1]];
			}
		}
	}
	return dp[nums.size()][target];
}