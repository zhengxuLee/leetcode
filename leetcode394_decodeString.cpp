#include "include.h"
/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

*/
string decodeString(string s)
{
	string res;
	stack<char>stk1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != ']')
		{
			stk1.push(s[i]);
		}
		else if (s[i] == ']')
		{
			int times = 0;
			string s;
			int flag = 0;
			while (!stk1.empty())
			{
				char c = stk1.top();
				if (isalpha(c))
					s = string(1, c) + s;
				else
					break;
				stk1.pop();
			}
			if (stk1.top() == '[')
				stk1.pop();
			int b = 1;
			while (!stk1.empty())
			{
				char c = stk1.top();
				if (isdigit(c))
				{
					times += b*(c - '0');
					b *= 10;
				}
				else
					break;
				stk1.pop();
			}
			for (int i = 0; i < times; ++i)
			{
				for (auto c : s)
					stk1.push(c);
			}
		}
	}
	while (!stk1.empty())
	{
		char c = stk1.top();
		res = string(1, c) + res;
		stk1.pop();
	}
	return res;
}



