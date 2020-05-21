#include "include.h"
bool search(vector<int>& nums, int target) 
{
	if (nums.empty())return false;
	int start = 0;
	int end = nums.size();
	while (start<end)
	{
		int middle = (start + end) / 2;
		if (nums[middle] == target)return true;
		if (nums[start]<nums[middle])//旋转点在middle右侧
		{
			int p1 = start;
			int p2 = middle;
			while (p1<p2)
			{
				int mmid = (p1 + p2) / 2;
				if (nums[mmid]>target)p2 = mmid;
				else if (nums[mmid] < target)p1 = mmid + 1;
				else return true;
			}
			start = middle;
		}
		else if (nums[start]>nums[middle])//旋转点在middle左侧
		{
			int p1 = middle;
			int p2 = end;
			while (p1<p2)
			{
				int mmid = (p1 + p2) / 2;
				if (nums[mmid]>target)p2 = mmid;
				else if (nums[mmid] < target)p1 = mmid + 1;
				else return true;
			}
			end = middle;
		}
		else//难以判断旋转点的位置
		{
			++start;
		}
	}
	return false;
}

