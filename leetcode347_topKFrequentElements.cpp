#include "include.h"
#include <xfunctional>

/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

vector<int> topKFrequent(vector<int>& nums, int k)
{
	vector<int>res;
	unordered_map<int, int>countMap;
	for (const auto& a : nums)countMap[a]++;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>queue1;
	auto itr = countMap.begin();
	for (int i = 0; i<k; ++i)
	{
		queue1.push(make_pair(itr->second, itr->first));
		++itr;
	}
	while (itr != countMap.end())
	{
		auto top = queue1.top();
		if ((itr->second)>top.first)
		{
			queue1.pop();
			queue1.push(make_pair(itr->second, itr->first));
		}
		++itr;
	}
	while (!queue1.empty())
	{
		auto top = queue1.top();
		res.push_back(top.second);
		queue1.pop();
	}
	return res;
}