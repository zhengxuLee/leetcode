#include"include.h"
/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

/*
vector<vector<char>>table;
void init()
{
	vector<char>vec1 = { '<', '<', '>', '>', '<' };
	vector<char>vec2 = { '<', '<', '<', '<', '<' };
	vector<char>vec3 = { '>', '>', '>', '>', '=' };
	table.push_back(vec1);
	table.push_back(vec1);
	table.push_back(vec2);
	table.push_back(vec2);
	table.push_back(vec3);
}

char optrCmp(char c1, char c2)
{
	int index1 = 0;
	unordered_map<char, int>map1;
	map1['+'] = 0;
	map1['-'] = 1;
	map1['*'] = 2;
	map1['/'] = 3;
	map1['#'] = 4;
	return table[map1[c2]][map1[c1]];
}
int cal(int num1, int num2, char c)
{
	switch (c)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num2 - num1;
	case '*':
		return num1*num2;
	case '/':
		return num2 / num1;
	default:
		return 0;
	}
}
int calculate2(string s)
{
	if (s.empty()) return 0;
	init();
	stack<int>numberStk;
	stack<int>operatorStk;
	operatorStk.push('#');
	s.push_back('#');
	while (!operatorStk.empty())
	{
		int i = 0;
		while (i < s.size())
		{
			char c = s[i];
			if (c == ' ')
			{
				++i;
				continue;
			}
			if (c >= '0' && c <= '9')
			{
				int num = 0;
				while (i < s.size())
				{
					num = 10 * num + (s[i] - '0');
					++i;
					if (s[i]<'0' || s[i]>'9')
						break;
				}
				numberStk.push(num);
				continue;
			}
			char t = operatorStk.top();
			char cmp = optrCmp(c, t);
			if (cmp == '<')
			{
				operatorStk.pop();
				int num1 = numberStk.top();
				numberStk.pop();
				int num2 = numberStk.top();
				numberStk.pop();
				int res = cal(num1, num2, t);
				numberStk.push(res);
			}
			else if (cmp == '>')
			{
				operatorStk.push(c);
				++i;
			}
			else if (cmp == '=')
			{
				operatorStk.pop();
				++i;
			}
			else
			{
				++i;
			}
		}
	}
	return numberStk.top();

}

*/

int calculate2(string s) {
	stack<int> myStack;
	char sign = '+';
	int res = 0, tmp = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		if (isdigit(s[i]))
			tmp = 10 * tmp + s[i] - '0';
		if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
			if (sign == '-')
				myStack.push(-tmp);
			else if (sign == '+')
				myStack.push(tmp);
			else {
				int num;
				if (sign == '*')
					num = myStack.top()*tmp;
				else
					num = myStack.top() / tmp;
				myStack.pop();
				myStack.push(num);
			}
			sign = s[i];
			tmp = 0;
		}
	}
	while (!myStack.empty()) {
		res += myStack.top();
		myStack.pop();
	}
	return res;
}

