#include "include.h"
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
{
	int xor1 = 0;
	for (int i = 0; i<data.size(); ++i)
	{
		xor1 ^= data[i];
	}
	int a = 1;
	int bit = 1;
	while (xor1>0)
	{
		xor1 = xor1 & a;
		if (xor1 == 1)break;
		xor1 = xor1 >> 1;
		++bit;
	}
	vector<int>group0;
	vector<int>group1;
	for (int i = 0; i < data.size(); ++i)
	{
		int num = data[i];
		int count = 1;
		while (count < bit)
		{
			num = num >> 1;
			++count;
		}
		if ((num & a) == 0)
			group0.push_back(data[i]);
		else
			group1.push_back(data[i]);
	}
	*num1 = 0;
	*num2 = 0;
	for (int i = 0; i < group0.size(); ++i)
	{
		(*num1) ^= group0[i];
	}
	for (int i = 0; i < group1.size(); ++i)
	{
		(*num2) ^= group1[i];
	}
}