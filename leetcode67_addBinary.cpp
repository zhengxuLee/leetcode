#include "include.h"

string addBinary(string a, string b)
{
	if (a.empty())return b;
	if (b.empty())return a;
	int size1 = a.size();
	int size2 = b.size();
	string res_str = size1 > size2 ? a : b;
	for (int i = 0; i<min(size1, size2); ++i)
	{
		res_str[res_str.size() - 1 - i] = a[size1 - 1 - i] + b[size2 - 1 - i] - '0';
	}
	int j = res_str.size() - 1;
	while (j>0)
	{
		if (res_str[j] >= '2')
		{
			res_str[j] -= 2;
			res_str[j - 1]++;
		}
		--j;
	}
	if (j == 0 && res_str[j] == '2')
	{
		string out(res_str.size() + 1, '0');
		for (int i = 0; i < res_str.size(); ++i)
		{
			out[i + 1] = res_str[i];
		}
		out[1] -= 2;
		out[0] += 1;
		return out;
	}
	else
	{
		return res_str;
	}
}

