#include "include.h"
/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
	vector<pair<int, int>>res(people.size());
	sort(people.begin(), people.end());
	vector<int>filled(people.size(), 0);
	for (int i = 0; i < people.size(); ++i)
	{
		int count = 0;
		for (int j = 0; j < people.size(); ++j)
		{
			if (filled[j] == 0 || (filled[j] == 1 && res[j].first >= people[i].first))
			{
				++count;
				if (filled[j] == 0 && count == people[i].second + 1)
				{
					res[j] = people[i];
					filled[j] = 1;
				}
			}
		}
	}
	return res;
}

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) 
{
	auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
	{ return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
	sort(people.begin(), people.end(), comp);
	vector<pair<int, int>> res;
	for (auto& p : people)
		res.insert(res.begin() + p.second, p);
	return res;
}
