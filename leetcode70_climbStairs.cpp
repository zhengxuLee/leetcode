#include "include.h"
int climbStairs(int n) 
{
	int res = 0;
	int* p = new int[n];
	p[0] = 1;
	p[1] = 2;
	for (int i = 2; i < n;++i)
	{
		p[i] = p[i - 1] + p[i - 2];
	}
	res = p[n - 1];
	delete[] p;
	return res;
}