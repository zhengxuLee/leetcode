#include "include.h"
//����������㣬��ͬΪ0����ͬΪ1
int singleNumber(vector<int>& nums)
{
	if (nums.empty())return -1;
	int a = 0;
	for (auto num : nums)
	{
		a ^= num;
	}
	return a;
}