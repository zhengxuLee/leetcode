#include "include.h"
/*
Given an array of integers, find out whether there are two distinct indices i and j in the array 
such that the absolute difference between nums[i] and nums[j] is at most t 
and the absolute difference between i and j is at most k.

Example 1:
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true

Example 3:
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	if (nums.empty())return false;
	set<long long>set1;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i>k)
			set1.erase(nums[i - k - 1]);
		long long num = nums[i];
		auto itr = set1.lower_bound(num);
		if (itr != set1.end() && *itr <= num + t)
			return true;
		set1.insert(num);
	}
	return false;
}