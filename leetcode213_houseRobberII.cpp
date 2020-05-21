#include "include.h"

/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have security system connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
because they are adjacent houses.


Example 2:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
*/

int robI(vector<int>& nums, int lo, int hi)//[lo,hi) 
{
	int res = 0;
	int length = hi - lo;
	if (length <= 0)return 0;
	if (length == 1)return nums[lo];
	if (length == 2)return max(nums[lo], nums[lo + 1]);
	vector<int>dp(length, 0);
	dp[0] = nums[lo];
	dp[1] = max(nums[lo], nums[lo + 1]);
	for (int i = 2; i < length; ++i)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + lo]);
	}
	return dp[length - 1];
}

int rob213(vector<int>& nums)
{
	int res = 0;
	if (nums.empty())return res;
	int length = nums.size();
	if (length <= 3)return *max_element(nums.begin(), nums.end());
	//根据最后一家有没有被抢劫，将环断裂为两种简单的情况
	return max(robI(nums, 1, length - 2) + nums[length - 1], robI(nums, 0, length - 1));
}