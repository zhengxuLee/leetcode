#include "include.h"
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"
*/

int expand(const string& s, int left, int right)
{
	if (s.empty())return 0;
	while (left >= 0 && right < s.length())
	{
		if (s[left] == s[right])
		{
			--left;
			++right;
		}
		else
		{
			break;
		}
	}
	return right - left - 1;
}
string longestPalindrome(string s)
{
	string res;
	if (s.empty())return res;
	int maxlength = 0;
	int start = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		int len1 = expand(s, i, i);
		int len2 = expand(s, i, i + 1);
		if (len1 >= maxlength)
		{
			maxlength = len1;
			start = i - len1 / 2;
		}
		if (len2 >= maxlength)
		{
			maxlength = len2;
			start = i - len2 / 2 + 1;
		}
	}
	return s.substr(start, maxlength);
}