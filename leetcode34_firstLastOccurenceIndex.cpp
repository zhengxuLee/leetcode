#include "include.h"
int lowerBounded(const vector<int>& nums, int target)
{
	if (nums.empty())return -1;
	int start = 0;
	int end = nums.size() - 1;
	while (start<end)
	{
		int mid = start + (end - start) / 2;
		if (nums[mid]>target)
			end = mid - 1;
		else if (nums[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return nums[start] == target ? start : -1;
}
int upperBounded(const vector<int>& nums, int target)
{
	if (nums.empty())return -1;
	int start = 0;
	int end = nums.size() - 1;
	while (start<end)
	{
		int mid = start + (end - start + 1) / 2;//这里尤其要注意
		if (nums[mid]>target)
			end = mid - 1;
		else if (nums[mid] < target)
			start = mid + 1;
		else
			start = mid;
	}
	return nums[start] == target ? start : -1;
}
vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int>res{ -1, -1 };
	if (nums.empty())return res;
	int lower_bounded = lowerBounded(nums, target);
	int upper_bounded = upperBounded(nums, target);
	res[0] = lower_bounded;
	res[1] = upper_bounded;
	return res;
}