#include "include.h"
//int longestConsecutive(vector<int>& nums)
//{
//	unordered_map<int, int> m;
//	int r = 0;
//	for (int i : nums)
//	{
//		if (m[i]) continue;
//		r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
//	}
//	return r;
//}
int longestConsecutive(vector<int>& nums)
{
	unordered_map<int, int>map1;
	int res = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		map1[nums[i]] = 1;
		int left = 0;
		for (int j = nums[i] - 1; j >= nums[i] - nums.size() + 1; --j)
		{
			if (map1[j] == 1)
			{
				++left;
			}
			else
				break;
		}
		int right = 0;
		for (int j = nums[i] + 1; j <= nums[i] + nums.size() - 1; ++j)
		{
			if (map1[j] == 1)
			{
				++right;
			}
			else
				break;
		}
		res = max(res, left + right + 1);
	}
	return res;
}
int main()
{
	vector<int>nums{ 100, 4, 200, 1, 3, 2 };
	longestConsecutive(nums);
	return 0;
}