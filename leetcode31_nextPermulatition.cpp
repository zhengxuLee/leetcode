#include "include.h"

void nextPermutation(vector<int>& nums)
{
	if (nums.size()<2)return;
	for (int i = nums.size() - 1; i>0; --i)
	{
		if (nums[i] > nums[i - 1])
		{
			for (int j = nums.size() - 1; j >= i; --j)
			{
				if (nums[j] > nums[i - 1])
				{
					swap(nums[j], nums[i - 1]);
					reverse(nums.begin() + i, nums.end());
					return;
				}
			}
		}
	}
	reverse(nums.begin(), nums.end());
}