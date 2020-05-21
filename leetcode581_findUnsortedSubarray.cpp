#include "include.h"

/*
Given an integer array, you need to find one continuous subarray 
that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

int findUnsortedSubarray(vector<int>& nums)
{
	if (nums.empty())return 0;
	//起始于从右往左最后一个比最小值大的元素
	int min1 = INT_MAX;
	int start = -1;
	for (int i = nums.size() - 1; i >= 0; --i)
	{
		min1 = min(min1, nums[i]);
		if (nums[i] > min1)
			start = i;
	}
	if (start == -1)return 0;
	//结束语从左往右最后一个比最大值小的元素
	int max1 = INT_MIN;
	int end = nums.size() - 1;
	for (int i = 0; i < nums.size(); ++i)
	{
		max1 = max(max1, nums[i]);
		if (nums[i] < max1)
			end = i;
	}
	return end - start + 1;
}