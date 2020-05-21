#include "include.h"

int mySqrt(int x) 
{
	if (x <= 0)return 0;
	int start = 1;
	int end = x;
	while (1)
	{
		if (end - start <= 1)
		{
			return start;
		}
		long long middle = start + (end - start)/2;
		if (middle*middle > x)
		{
			end = middle;
		}
		else
		{
			start = middle;
		}
	}
}
