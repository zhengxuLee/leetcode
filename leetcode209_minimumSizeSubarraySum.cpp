#include"include.h"
/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ¡Ý s. If there isn't one, return 0 instead.
Example:
Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.

Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

int minSubArrayLen1(int s, vector<int>& nums)
{
	if (nums.empty() || s <= 0)return 0;
	int res = INT_MAX;
	for (int i = 0; i < nums.size(); ++i)
	{
		int sum = 0;
		int j = i;
		while (j < nums.size() && sum < s)
		{
			sum = sum + nums[j];
			++j;
		}
		if (sum >= s)
		{
			res = min(res, j - i);
		}
	}
	return res == INT_MAX ? 0 : res;
}

int minSubArrayLen2(int s, vector<int>& nums)
{
	if (nums.empty() || s <= 0)return 0;
	int res = INT_MAX;
	vector<int>preSum(nums.size(), nums[0]);
	for (int i = 1; i < nums.size(); ++i)
	{
		preSum[i] = preSum[i - 1] + nums[i];
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		int tmp = preSum[i] + s - nums[i];
		auto itr = lower_bound(preSum.begin(), preSum.end(), tmp);
		if (itr != preSum.end())
		{
			int len = itr - (preSum.begin() + i) + 1;
			res = min(res, len);
		}
	}
	return res == INT_MAX ? 0 : res;
}
int minSubArrayLen3(int s, vector<int>& nums)
{
	if (nums.empty() || s <= 0)return 0;
	int res = INT_MAX;
	int left = 0;
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		sum += nums[i];
		while (sum >= s)
		{
			res = min(res, i - left + 1);
			sum -= nums[left];
			left++;
		}
	}
	return res == INT_MAX ? 0 : res;
}