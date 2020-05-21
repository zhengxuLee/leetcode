#include "include.h"
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1
compute how much water it is able to trap after raining.
*/
int trap(vector<int>& height)
{
	int left = 0;
	int right = height.size() - 1;
	int maxLeft = 0;
	int maxRight = 0;
	int res = 0;
	while (left < right)
	{
		if (height[left] < height[right])
		{
			if (height[left] >= maxLeft)maxLeft = height[left];
			else res += maxLeft - height[left];
			++left;
		}
		else
		{
			if (height[right] >= maxRight)maxRight = height[right];
			else res += maxRight - height[right];
			--right;
		}
	}
	return res;
}




