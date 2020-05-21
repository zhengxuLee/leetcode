#include "include.h"
/*
题目：求两个字符串的最长公共子序列
状态转移方程：C[i,j]=C[i-1][j-1]					str1[i]==str2[j]
				   =max(C[i][j-1],C[i-1][j])	str1[i]!=str2[j]
*/
int longestCommonSubseq(string str1, string str2)
{
	int res = 0;
	if (str1.empty()||str2.empty())return 0;
	int** dp_map = new int*[str1.size()];
	for (int i = 0; i < str1.size();++i)
	{
		dp_map[i] = new int[str2.size() + 1];
	}
	for (int i = 0; i <= str1.size();++i)
	{
		dp_map[0][i] = 0;
	}
	for (int j = 0; j <= str2.size(); ++j)
	{
		dp_map[j][0] = 0;
	}
	for (int i = 1; i <= str1.size();++i)
	{
		for (int j = 1; j <= str2.size();++j)
		{
			if (str1[i-1]==str2[j-1])
			{
				dp_map[i][j] = dp_map[i - 1][j - 1] + 1;
			}
			else
			{
				dp_map[i][j] = max(dp_map[i][j - 1], dp_map[i - 1][j]);
			}
		}
	}
	res = dp_map[str1.size()][str2.size()];
	for (int i = 0; i < str1.size(); ++i)
	{
		delete[]dp_map[i];
	}
	return res;
}

