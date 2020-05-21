#include "include.h"
/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:
Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"

Example 2:
Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
*/
//非法的括号将合法的括号分隔开。
int longestValidParentheses1(string s)
{
	if (s.empty())return 0;
	stack<int>stack1;
	stack1.push(-1);
	for (int i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if (c == '(')
			stack1.push(i);
		else if (c == ')')
		{
			if (!stack1.empty() && s[stack1.top()] == '(')
			{
				stack1.pop();
			}
			else
			{
				stack1.push(i);
			}
		}
	}
	int last = s.size();
	int maxLength = 0;
	while (!stack1.empty())
	{
		int top = stack1.top();
		maxLength = max(maxLength, last - top - 1);
		last = top;
		stack1.pop();
	}
	return maxLength;
}

int longestValidParentheses2(string s)
{
	if (s.empty())return 0;
	vector<int>dp(s.size(), 0);
	int maxLength = 0;
	for (int i = 1; i < s.size(); ++i)
	{
		if (s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				dp[i] = 2;
				if (i >= 2)dp[i] += dp[i - 2];
			}
			else
			{
				int prev = i - 1 - dp[i - 1];
				if (prev >= 0 && prev < s.length() && s[prev] == '(')
				{
					dp[i] = dp[i - 1] + 2;
					if (prev >= 1)dp[i] += dp[prev - 1];
				}
			}
		}
		maxLength = max(maxLength, dp[i]);
	}
	return maxLength;
}
