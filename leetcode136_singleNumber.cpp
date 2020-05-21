#include "include.h"
//利用异或运算，相同为0，不同为1
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