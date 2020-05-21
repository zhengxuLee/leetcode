#include "include.h"
/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:
Input: [1, 5, 11, 5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/
bool canSumtoTarget(const vector<int>&nums, int start, int target)
{
	if (nums[start] > target)return false;
	if (nums[start] == target)return true;
	if (start > nums.size() - 1)return false;
	return canSumtoTarget(nums, start + 1, target - nums[start]) ||
		canSumtoTarget(nums, start + 1, target);
}
bool canPartition1(vector<int>& nums) {
	if (nums.empty())return true;
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if (sum % 2 == 1)return false;
	int target = sum / 2;
	sort(nums.rbegin(), nums.rend());
	return canSumtoTarget(nums, 0, target);
}

bool canPartition2(vector<int>& nums)
{
	if (nums.empty())return true;
	sort(nums.begin(), nums.end());
	int sum = 0;
	for (int i = 0; i < nums.size(); ++i)
		sum += nums[i];
	if (sum % 2 != 0)return false;
	int target = sum / 2;
	unordered_set<int>set1;
	for (int j = 0; j<nums.size(); ++j)
	{
		if (nums[j]>target)
			return false;
		if (nums[j] == target)return true;
		int pair = target - nums[j];
		if (set1.find(pair) != set1.end())
		{
			return true;
		}
		else
		{
			for (auto num : set1)
			{
				set1.insert(num + nums[j]);
			}
			set1.insert(nums[j]);
		}
	}
	return false;
}