#include "include.h"
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.*/

bool canJump1(vector<int>&nums, int index)
{
	if (nums.empty() || index > nums.size() - 1)return false;
	if (index == 0)return true;
	for (int i = index - 1; i >= 0; --i)
	{
		if (i + nums[i] >= index)
			return canJump1(nums, i);
	}
	return false;
}
bool canJump1(vector<int>& nums)
{
	if (nums.empty())return false;
	return canJump1(nums, nums.size() - 1);
}
//--------------------------Ì°ÐÄËã·¨-------------------------------
bool canJump2(vector<int>& nums)
{
	if (nums.empty())return true;
	int last_good = nums.size() - 1;
	for (int i = nums.size() - 1; i >= 0;--i)
	{
		if (i+nums[i]>=last_good)
		{
			last_good = i;
		}
	}
	return last_good == 0;
}

