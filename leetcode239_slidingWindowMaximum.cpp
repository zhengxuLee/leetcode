#include "include.h"
/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/


vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
	vector<int>res;
	if (nums.empty() || k <= 0)return res;
	if (k >= nums.size())
	{
		res.push_back(*max_element(nums.begin(), nums.end()));
		return res;
	}
	deque<int>deque1;//»º´æÏÂ±ê
	for (int i = 0; i<nums.size(); ++i)
	{
		if (deque1.empty())
			deque1.push_back(i);
		else
		{
			while (!deque1.empty() && nums[i]>nums[deque1.back()])
			{
				deque1.pop_back();
			}
			deque1.push_back(i);
		}
		if (i >= k - 1)
		{
			int index = deque1.front();
			res.push_back(nums[index]);
			if (!deque1.empty() && deque1.back() - deque1.front() >= k - 1)
				deque1.pop_front();
		}
	}
	return res;
}