#include "include.h"
/*
Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:
Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23

Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.


*/

int calculate(string s)
{
	if (s.empty())return 0;
	stack<int>numberStk;
	int res = 0;
	int sign = 1;
	int num = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			res += sign*num;
			num = 0;
			sign = s[i] == '+' ? 1 : -1;
		}
		else if (s[i] == '(')
		{
			numberStk.push(res);
			numberStk.push(sign);
			num = 0;
			res = 0;
			sign = 1;
		}
		else if (s[i] == ')')
		{
			res += sign*num;
			num = 0;
			int s = numberStk.top();
			numberStk.pop();
			int p = numberStk.top();
			numberStk.pop();
			res = p + s*res;
		}
	}
	res += sign*num;
	return res;
}
