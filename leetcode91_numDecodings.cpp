#include "include.h"

int numDecodings(string s) 
{
	if (s.empty())return 0;
	int res_num = 0;
	int* dp = new int[s.size()];
	dp[0] = 1;
	if (s.size()>=2)
	{
		dp[1] = 1;
		string prefix2 = s.substr(2);
		int num = (prefix2[0] - '0') * 10 + prefix2[1] - '0';
		if (num % 10 == 0)
		{
			if (num == 10 || num == 20)
			{
				dp[1] = 1;
			}
			else
			{
				dp[1] = 0;
			}
		}
		else
		{
			if (num > 10 && num <= 26)
			{
				dp[1] = 2;
			}
		}
	}
	for (int i = 2; i < s.size();++i)
	{
		string last2 = s.substr(i - 1);
		dp[i] = dp[i - 1];
		int num = (last2[0] - '0') * 10 + last2[1] - '0';
		if (num%10==0)
		{
			if (num==10 || num==20)
			{
				dp[i] = dp[i - 2];
			}
			else
			{
				dp[i] = 0;
			}
		}
		else
		{
			if (num >10 && num <= 26)
			{
				dp[i] = dp[i - 1] + dp[i - 2];
			}
		}
	}
	res_num = dp[s.size() - 1];
	delete[]dp;
	return res_num;
}