#include"include.h"

int countUnvalid(const string& s)
{
	stack<char>stack1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != '(' && s[i] != ')')
			continue;
		if (stack1.empty())
			stack1.push(s[i]);
		else
		{
			if (stack1.top() == '(' && s[i] == ')')
			{
				stack1.pop();
			}
			else
			{
				stack1.push(s[i]);
			}
		}
	}
	return stack1.size();
}
void dfs(string current, const string& s, int i, int unvalid, vector<string>& res)
{
	if (countUnvalid(current) == 0 && current.length() + unvalid == s.length())
	{
		res.push_back(current);
		return;
	}
	if (i == s.length())return;
	if (i >= s.length() || i - current.length() > unvalid)
		return;
	dfs(current, s, i + 1, unvalid, res);
	current.push_back(s[i]);
	dfs(current, s, i + 1, unvalid, res);
}
vector<string> removeInvalidParentheses(string s)
{
	int unvalidNumber = countUnvalid(s);
	vector<string> res;
	string current;
	dfs(current, s, 0, unvalidNumber, res);
	return res;
}

