#include "include.h"
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
Jump 1 step from index 0 to 1, then 3 steps to the last index.

Note:
You can assume that you can always reach the last index.

*/
int leetcode45_jump1(vector<int>& nums)
{
	if (nums.size() <= 1) return 0;
	if (nums[0] >= nums.size() - 1)return 1;
	int target = nums.size() - 1;
	int count = 0;
	while (target > 0)
	{
		for (int i = 0; i < target; ++i)
		{
			if (nums[i] + i >= target)
			{
				target = i;
				++count;
				break;
			}
		}
	}
	return count;
}
//»¬¶¯´°¿Ú
int leetcode45_jump2(vector<int>& nums)
{
	if (nums.size() <= 1) return 0;
	if (nums[0] >= nums.size() - 1)return 1;
	int first = 0;
	int last = 0;
	int target = nums.size() - 1;
	int count = 0;
	while (last < target)
	{
		int max1 = last + 1;
		for (first; first <= last; ++first)
		{
			max1 = max(max1, first + nums[first]);
		}
		first = last + 1;
		last = max1;
		++count;
	}
	return count;
}

