#include "include.h"


//------------------方法一：递归减治----------------
//bool wordBreak(string s, vector<string>& wordDict) 
//{
//	if (s.empty())return true;
//	if (wordDict.empty())return false;
//	auto itr = find(wordDict.begin(), wordDict.end(), s);
//	if (itr!=wordDict.end())
//	{
//		return true;
//	}
//	else
//	{
//		int i = 1;
//		for (i; i < s.length();++i)
//		{
//			string s1 = s.substr(0, i);
//			string s2 = s.substr(i);
//			if (wordBreak(s1, wordDict) && wordBreak(s2, wordDict))
//			{
//				return true;
//			}
//		}
//		if (i==s.length())
//		{
//			return false;
//		}
//	}
//}

//------------------方法二：动态规划----------------
bool wordBreak(string s, vector<string>& wordDict)
{
	if (s.empty())return true;
	if (wordDict.empty())return false;
	vector<int>wordBreak_dp(s.size()+1, 0);
	wordBreak_dp[0] = 1;
	for (int i = 1; i <= s.size();++i)
	{
		for (int j = i; j >= 0;--j)
		{
			string s2 = s.substr(j, i - j);
			if (wordBreak_dp[j] && find(wordDict.begin(), wordDict.end(), s2) != wordDict.end())
			{
				wordBreak_dp[i] = 1;
				break;
			}
		}
	}
	return wordBreak_dp[s.size()];
}
