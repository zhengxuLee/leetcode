#include "include.h"
/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
Example:
Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.*/
string minWindow(string s, string t)
{
	string res;
	if (s.size() < t.size())return res;
	unordered_map<char, int>count;
	for (int i = 0; i < t.size(); ++i)count[t[i]]++;
	int start = 0;
	int end = 0;
	int begin = 0;
	int minLength = INT_MAX;
	int number = count.size();
	while (end < s.size())
	{
		if (count.find(s[end]) != count.end())
		{
			--count[s[end]];
			if (count[s[end]] == 0)
			{
				--number;
			}
		}
		++end;
		while (number == 0)
		{
			if (count.find(s[start]) != count.end())
			{
				++count[s[start]];
				if (count[s[start]] > 0)
				{
					++number;
				}
			}
			if (end - start <= minLength)
			{
				minLength = end - start;
				begin = start;
			}
			++start;
		}
	}
	return minLength == INT_MAX ? res : s.substr(begin, minLength);
}