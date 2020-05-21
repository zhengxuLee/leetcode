#include "include.h"
/*
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
	["ate","eat","tea"],
	["nat","tan"],
	["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.


*/

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
	vector<vector<string>>res_group;
	map<string, vector<string>>map_tmp;
	for (int i = 0; i < strs.size(); ++i)
	{
		string str = strs[i];
		string key(str);
		sort(key.begin(), key.end());
		map_tmp[key].push_back(str);
	}
	for (auto item : map_tmp)
	{
		res_group.push_back(item.second);
	}
	return res_group;
}
