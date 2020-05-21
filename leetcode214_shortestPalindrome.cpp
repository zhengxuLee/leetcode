#include "include.h"

string shortestPalindrome(string s)
{
	string res;
	if (s.empty())return res;
	string s1;
	for (int i = 0; i < s.length(); ++i)
	{
		s1.push_back('#');
		s1.push_back(s[i]);
	}
	s1.push_back('#');
	int mirror = 0;
	int length1 = s1.length();
	for (int j = length1 / 2; j >= 0; --j)
	{
		int k = j - 1;
		for (; k >= 0; --k)
		{
			if (s1[k] != s1[2 * j - k])
			{
				break;
			}
		}
		if (k<0)
		{
			mirror = j;
			break;
		}
	}
	for (int i = length1 - 1; i>mirror; --i)
	{
		if (s1[i] != '#')
		{
			res.push_back(s1[i]);
		}
	}
	for (int i = mirror; i < length1; ++i)
	{
		if (s1[i] != '#')
		{
			res.push_back(s1[i]);
		}
	}
	return res;
}