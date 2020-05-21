#include "include.h"
/*
A peak element is an element that is greater than its neighbors.
Given an input array nums, where nums[i] ¡Ù nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that nums[-1] = nums[n] = -¡Þ.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
or index number 5 where the peak element is 6.

Note:
Your solution should be in logarithmic complexity.
*/
int findPeakElement(vector<int>& nums) 
{
	if (nums.empty())return 0;
	if (nums.size() == 1)return nums[0];
	int start = 0;
	int end = nums.size() - 1;
	while (start<end)
	{
		int middle = (start + end) / 2;
		if (nums[middle]>nums[middle+1])
		{
			end = middle;
		}
		else if (nums[middle]<nums[middle + 1])
		{
			start = middle + 1;
		}
		else
		{
			++start;
		}
	}
	return start;
}