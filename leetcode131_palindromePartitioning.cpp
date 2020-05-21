#include "include.h"
bool isPalindrome1(string s)
{
	if (s.empty())return true;
	int i = 0;
	int j = s.size() - 1;
	while (i<j)
	{
		if (s[i] != s[j])return false;
		++i;
		--j;
	}
	return true;
}
//--------------µÝ¹é-----------------
//vector<vector<string>> partition(string s)
//{
//	vector<vector<string>>partitions;
//	if (s.empty())return partitions;
//	for (int i = 1; i <= s.size();++i)
//	{
//		string prefix = s.substr(0, i);
//		if (isPalindrome(prefix))
//		{
//			string last = s.substr(i);
//			if (last.empty())
//			{
//				vector<string>tmp = { prefix };
//				partitions.push_back(tmp);
//			}
//			else
//			{
//				vector<vector<string>>res = partition(last);
//				for (auto solution : res)
//				{
//					solution.insert(solution.begin(), prefix);
//					partitions.push_back(solution);
//				}
//			}
//		}
//	}
//	return partitions;
//}
//--------------µÝ¹é-----------------


//-------------¶¯Ì¬¹æ»®---------------
vector<vector<string>> partition(string s)
{
	vector<vector<string>>partitions;
	if (s.empty())return partitions;
	unordered_map<string, vector<vector<string>>>dp_map;
	string tmp(1, s[0]);
	dp_map[tmp].push_back(vector<string>(1, tmp));
	for (int i = 1; i < s.size();++i)
	{
		string prefix = s.substr(0, i+1);
		for (int j = i; j >= 0; --j)
		{
			string last = s.substr(j, i - j + 1);
			if (isPalindrome1(last))
			{
				string substr = s.substr(0, j);
				if (j == 0)
				{
					dp_map[prefix].push_back(vector<string>(1,last));
				}
				else
				{
					for (auto path : dp_map[substr])
					{
						path.push_back(last);
						dp_map[prefix].push_back(path);
					}
				}
			}
		}
	}
	return dp_map[s];
}