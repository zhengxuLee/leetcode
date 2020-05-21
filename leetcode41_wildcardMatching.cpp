#include "include.h"
/*

Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

Example 4:
Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".

Example 5:
Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/

bool isMatch(string s, string p) 
{
	if (s.empty() && p.empty())return true;
	vector<vector<int>>dp(s.length() + 1, vector<int>(p.length() + 1, 0));
	dp[0][0] = 1;
	for (int j = 1; j <= p.length(); ++j)
	{
		if (p[j - 1] == '*')dp[0][j] = dp[0][j - 1];
		else dp[0][j] = 0;
	}
	for (int i = 1; i <= s.length(); ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 1; i <= s.length(); ++i)
	{
		for (int j = 1; j <= p.length(); ++j)
		{
			if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*')
			{
				if (j >= 2 && p[j - 2] == '*')
				{
					dp[i][j] = dp[i][j - 1];
					continue;
				}
				if (j >= 2 && (p[j - 2] == s[i - 1] || p[j - 2] == '?'))
				{
					dp[i][j] = dp[i - 1][j - 2];
				}
				dp[i][j] = max(dp[i][j],dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	return dp[s.length()][p.length()] == 1;
}


