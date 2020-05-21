#include "include.h"

/*
题目：用1,3,5三种硬币凑够17元，使得硬币的数量最少
状态转移方程为d(i)=min{d(i-vj)+1};
*/
int minCoinNumber(int target)
{
	int res = 0;
	int* d = new int[target+1];
	d[0] = 0;
	for (int i = 1; i <= target;++i)
	{
		if (i<3)
		{
			d[i] = d[i - 1] + 1;
		}
		else if (i<5)
		{
			d[i] = min(d[i - 1] + 1, d[i - 3] + 1);
		}
		else
		{
			d[i] = min(min(d[i - 1] + 1, d[i - 3] + 1), d[i - 5] + 1);
		}
		
	}
	res = d[target];
	delete[] d;
	return res;
}

