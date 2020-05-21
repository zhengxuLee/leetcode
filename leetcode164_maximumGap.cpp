#include "include.h"
/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Return 0 if the array contains less than 2 elements.

Example 1:
Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
(3,6) or (6,9) has the maximum difference 3.

Example 2:
Input: [10]
Output: 0

*/
//桶排序的思想，但还有优化的余地，每个桶里面只需要记录区间最小值和最大值即可
//int maximumGap(vector<int>& nums)
//{
//	if (nums.size() < 2)return 0;
//	int max_gap = 0;
//	int lo = *min_element(nums.begin(), nums.end());
//	int hi = *max_element(nums.begin(), nums.end());
//	double range_size = (double)(hi - lo) / nums.size();
//	map<int, vector<int>>bucket;
//	for (int i = 0; i < nums.size();++i)
//	{
//		int bucket_index = (nums[i] - lo) / range_size;
//		bucket[bucket_index].push_back(nums[i]);
//	}
//	//该单元的最小值减上一单元的最大值
//	int last_max = lo;
//	for (auto cell:bucket)
//	{
//		max_gap = max(max_gap, *min_element(cell.second.begin(), cell.second.end()) - last_max);
//		last_max = *max_element(cell.second.begin(), cell.second.end());
//	}
//	return max_gap;
//}

int maximumGap(vector<int>& nums)
{
	if (nums.size() < 2)return 0;
	int max_gap = 0;
	int lo = *min_element(nums.begin(), nums.end());
	int hi = *max_element(nums.begin(), nums.end());
	double range_size = (double)(hi - lo) / nums.size();
	map<int, pair<int, int>>bucket;
	for (int i = 0; i < nums.size(); ++i)
	{
		int bucket_index = (nums[i] - lo) / range_size;
		if (bucket.find(bucket_index)==bucket.end())
		{
			bucket[bucket_index] = make_pair(nums[i], nums[i]);
		}
		else
		{
			bucket[bucket_index].first = min(bucket[bucket_index].first, nums[i]);
			bucket[bucket_index].second = max(bucket[bucket_index].second, nums[i]);
		}
	}
	//该单元的最小值减上一单元的最大值
	int last_max = lo;
	for (auto cell:bucket)
	{
		max_gap=max(cell.second.first - last_max, max_gap);
		last_max = cell.second.second;
	}
	return max_gap;
}