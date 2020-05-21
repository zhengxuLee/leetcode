#include "include.h"

/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.

*/

int expand(const string& s, int start, int end)
{
	if (s.empty())return 0;
	int res = 0;
	while (start >= 0 && end <= s.size() - 1)
	{
		if (s[start] == s[end])
		{
			++res;
			--start;
			++end;
		}
		else
		{
			break;
		}
	}
	return res;
}
int countSubstrings(string s)
{
	if (s.empty())return 0;
	int res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res += (expand(s, i, i + 1) + expand(s, i - 1, i + 1) + 1);
	}
	return res;
}