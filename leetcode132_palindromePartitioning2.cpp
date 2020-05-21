#include "include.h"
bool isPalindrome(string s,int start,int end)
{
	if (start>=end)return true;
	int i = start;
	int j = end-1;
	while (i < j)
	{
		if (s[i] != s[j])return false;
		++i;
		--j;
	}
	return true;
}
int minCut(string s) 
{
	if (s.empty())return 0;
	if (isPalindrome(s,0,s.size()))return 0;
	vector<int>cut_dp(s.size(), 0);
	for (int i = 1; i < s.size();++i)
	{
		cut_dp[i] = cut_dp[i - 1] + 1;
		for (int j = i; j >= 0; --j)
		{
			if (isPalindrome(s,j,i+1))
			{
				if (j>0)
				{
					cut_dp[i] = min(cut_dp[i], cut_dp[j-1] + 1);
				}
				else
					cut_dp[i] = 0;
			}
		}
	}
	return cut_dp[s.size() - 1];
}