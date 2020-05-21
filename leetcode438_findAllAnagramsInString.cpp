#include "include.h"
/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


vector<int> findAnagrams(string s, string p)
{
	vector<int>res;
	if (s.empty() || p.empty())return res;
	unordered_map<char, int>map1;
	for (auto c : p)
		++map1[c];
	int count = map1.size();
	int start = 0;
	int end = 0;
	while(end < s.size())
	{
		if (map1.find(s[end]) != map1.end())
		{
			--map1[s[end]];
			if (map1[s[end]] == 0)
				--count;
		}
		++end;
		while (count==0)
		{
			if (map1.find(s[start]) != map1.end())
			{
				map1[s[start]]++;
				if (map1[s[start]] > 0)
					++count;
			}
			if (end-start==p.length())
			{
				res.push_back(start);
			}
			++start;
		}
	}
	return res;
}

