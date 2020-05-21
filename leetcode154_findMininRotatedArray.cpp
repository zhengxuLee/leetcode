#include "include.h"
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0, 1, 2, 4, 5, 6, 7] might become[4, 5, 6, 7, 0, 1, 2])
Find the minimum element.
The array may contain duplicates.
Example 1:
Input : [1, 3, 5]
Output : 1

Example 2:
Input : [2, 2, 2, 0, 1]
Output : 0
*/
int findMin2(vector<int>& nums)
{
	if (nums.empty())return 0;
	int start = 0;
	int end = nums.size() - 1;
	while (start < end)
	{
		if (nums[start] < nums[end])return nums[start];
		int middle = (start + end) / 2;
		if (nums[middle]<nums[start])
			end = middle;
		else if (nums[middle]>nums[start])
			start = middle + 1;
		else
			++start;
	}
	return nums[start];
}