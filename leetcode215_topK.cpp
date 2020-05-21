#include "include.h"

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:
Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.
*/
int partition(vector<int>& nums, int start, int last, int pivot)
{
	while (1)
	{
		while (nums[start] < pivot)
			++start;
		--last;
		while (pivot < nums[last])
			--last;
		if (start >= last)
			return start;
		swap(nums[start], nums[last]);
		++start;
	}
}
int findKthLargest(vector<int>& nums, int k)
{
	if (nums.empty())return 0;
	if (nums.size() <= k)
		return *min_element(nums.begin(), nums.end());
	int start = 0;
	int last = nums.size();
	while (last - start > 3)
	{
		int cut = partition(nums, start, last, nums[start]);
		if (cut <= k)
		{
			start = cut;
		}
		else
		{
			last = cut;
		}
	}
	sort(nums.begin() + start, nums.begin() + last);
	return nums[k];
}
