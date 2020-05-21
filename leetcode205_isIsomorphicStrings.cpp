#include "include.h"

/*

Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true

Note:
You may assume both s and t have the same length.

*/

bool isIsomorphic(string s, string t)
{
	if (s.empty() && t.empty())return true;
	if (s.size() != t.size())return false;
	size_t length = s.length();
	unordered_map<char, vector<size_t>>map1;
	unordered_map<char, vector<size_t>>map2;
	for (size_t i = 0; i < length; ++i)
	{
		map1[s[i]].push_back(i);
		map2[t[i]].push_back(i);
	}
	for (size_t i = 0; i < length; ++i)
	{
		if (map1[s[i]] != map2[t[i]])
			return false;
	}
	return true;
}