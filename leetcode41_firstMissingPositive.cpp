#include "include.h"
int firstMissingPositive(vector<int>& nums)
{
	int i = 0;
	while (i < nums.size())
	{
		if (nums[i] == i + 1 || nums[i] <= 0 || nums[i] > nums.size()) i++;
		else if (nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);//注意这里没有++i
		else i++;
	}
	i = 0;
	while (i < nums.size() && nums[i] == i + 1) i++;
	return i + 1;

}


