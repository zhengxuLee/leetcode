#include "include.h"
/*
Example 1
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
int search(vector<int>& nums, int target)
{
	if (nums.empty())return -1;
	int start = 0;
	int end = nums.size() - 1;
	while (start < end)
	{
		int middle = start + (end - start) / 2;
		if (target == nums[middle])return middle;
		if (nums[middle] >= nums[start])
		{
			if (target >= nums[start] && target < nums[middle])
			{
				end = middle - 1;
			}
			else
			{
				start = middle + 1;
			}
		}
		else
		{
			if (target > nums[middle] && target <= nums.back())
			{
				start = middle + 1;
			}
			else
			{
				end = middle - 1;
			}
		}
	}
	return nums[start] == target ? start : -1;
}