#include "include.h"


void sortColors(vector<int>& nums) 
{
	if (nums.empty())return;
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < nums.size();++i)
	{
		switch (nums[i])
		{
		case 0:
			++count0;
			break;
		case 1:
			++count1;
				break;
		case 2:
			++count2;
				break;
		default:
			break;
		}
	}
	fill(nums.begin(), nums.begin() + count0, 0);
	fill(nums.begin()+count0, nums.begin() + count0+count1, 1);
	fill(nums.begin() + count0 + count1, nums.end(), 2);
	return;
}