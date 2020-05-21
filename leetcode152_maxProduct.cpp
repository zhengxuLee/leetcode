#include "include.h"
/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/
//-----------------方法一：最原始的动态规划-----------------
//int maxProduct(vector<int>& nums) 
//{
//	if (nums.empty())return 0;
//	vector<int>maxProduct_dp(nums.size(), 0);
//	maxProduct_dp[0] = nums[0];
//	for (int i = 1; i < nums.size();++i)
//	{
//		maxProduct_dp[i] = maxProduct_dp[i - 1];
//		int maxProduct = 1;
//		for (int j = i; j >= 0;--j)
//		{
//			maxProduct = maxProduct*nums[j];
//			maxProduct_dp[i] = max(maxProduct_dp[i], maxProduct);
//		}
//	}
//	return maxProduct_dp[nums.size() - 1];
//}


//-----------------方案二：优化版的动态规划-----------------
int maxProduct(vector<int>& nums)
{
	if (nums.empty())return 0;
	int maxPro = nums[0];
	int lmin = nums[0];
	int lmax = nums[0];
	for (int i = 1; i < nums.size();++i)
	{
		if (nums[i]<0)
		{
			swap(lmin, lmax);
		}
		lmax = max(nums[i],lmax * nums[i]);
		lmin = min(nums[i], lmin * nums[i]);
		maxPro = max(maxPro, lmax);
	}
	return maxPro;
}