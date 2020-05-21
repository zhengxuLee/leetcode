#include "include.h"
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/
int maxSubArray(vector<int>& nums) 
{
	if (nums.empty())
	{
		return 0;
	}
	//记录最大和
	int max_sum = INT_MIN;
	int start_index = 0;
	int end_index = 0;
	int i = 0;
	while (i<nums.size())
	{
		max_sum = max(max_sum, nums[i]);
		if (nums[i]<=0)
		{
			++i;
			continue;
		}
		start_index = i;
		int pre_sum = nums[i];
		int j = i + 1;
		for (j; j < nums.size();++j)
		{
			pre_sum += nums[j];
			if (pre_sum<=0)
			{
				i = j + 1;
				break;
			}
			if (pre_sum>max_sum)
			{
				end_index = j;
				max_sum = pre_sum;
			}
		}
		if (j==nums.size())
		{
			break;
		}
	}
	return max_sum;
}

