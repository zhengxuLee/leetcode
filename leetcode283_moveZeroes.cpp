#include "include.h"

/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

void moveZeroes1(vector<int>& nums)
{
	if (nums.empty())return;
	int i = 0;
	while (1)
	{
		while (i < nums.size() && nums[i] != 0)
		{
			++i;
		}
		int j = i;
		while (j < nums.size() && nums[j] == 0)
		{
			++j;
		}
		if (j == nums.size())return;
		swap(nums[i], nums[j]);
	}
	return;
}

void moveZeroes2(vector<int>& nums)
{
	if (nums.empty())return;
	int i = 0;
	for (int j = 0; j < nums.size(); ++j)
	{
		if (nums[j] != 0)
		{
			nums[i] = nums[j];
			++i;
		}
	}
	for (i; i < nums.size(); ++i)
	{
		nums[i] = 0;
	}
}