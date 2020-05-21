#include "include.h"

/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. 
If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. 
After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ¡Ü n ¡Ü 500, 0 ¡Ü nums[i] ¡Ü 100

Example:
Input: [3,1,5,8]
Output: 167
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

*/

int maxCoins(vector<int>& nums)
{
	if (nums.empty())return 0;
	if (nums.size() == 1)return nums[0];
	int n = nums.size();
	vector<int>newNums(n + 2, 0);
	newNums[0] = 1;
	for (int i = 0; i < n; ++i)newNums[i + 1] = nums[i];
	newNums[n + 1] = 1;
	vector<vector<int>>dp(n + 2, vector<int>(n + 2, 0));
	for (int j = 1; j <= n; ++j)
	{
		for (int i = j; i >= 1; --i)
		{
			for (int k = i; k <= j; ++k)
			{
				dp[i][j] = max(dp[i][j], newNums[i - 1] * newNums[k] * newNums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
			}

		}
	}
	return dp[1][n];
}