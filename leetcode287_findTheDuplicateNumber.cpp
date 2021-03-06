#include "include.h"

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:
Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/


int findDuplicate1(vector<int>& nums)
{
	vector<int>count(nums.size() + 1, 0);
	for (int i = 0; i<nums.size(); ++i)
	{
		++count[nums[i]];
		if (count[nums[i]]>1)
			return nums[i];
	}
	return -1;
}


int Count(const vector<int>&nums, int start, int end)
{
	int count = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] >= start && nums[i] <= end)
			++count;
	}
	return count;
}
int findDuplicate2(vector<int>& nums)
{
	if (nums.empty())return -1;
	int start = 1;
	int end = nums.size() - 1;
	while (start<end)
	{
		int mid = start + (end - start) / 2;
		int count = Count(nums, start, mid);
		if (count>mid - start + 1)
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	return start;
}