/*
题目：求最长非降子序列的长度，不要求连续
状态转移方程：d(i)=max(1,d(j)+1)  其中A[j]<=A[i]
*/
#include "include.h"
int longestIncreasingSeq(vector<int>& vec)
{
	int res = 0;
	int *d = new int[vec.size()];
	d[0] = 1;
	for (int i = 1; i < vec.size(); ++i)
	{
		int max_length = 1;
		for (int j = 0; j < i; ++j)
		{
			if (vec[j] <= vec[i])
			{
				if (max_length < d[j] + 1)
				{
					max_length = d[j] + 1;
				}
			}
		}
		d[i] = max_length;
	}
	res = d[vec.size() - 1];
	delete[] d;
	return res;
}