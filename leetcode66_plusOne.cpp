#include "include.h"

vector<int> plusOne(vector<int>& digits) 
{
	if (digits.empty())
	{
		return vector<int>{1};
	}
	digits.back()++;
	if (digits.back()<10)
	{
		return digits;
	}
	else
	{
		int j = digits.size() - 1;
		while (digits[j]>10 && j>0)
		{
			digits[j] -= 10;
			digits[j - 1] += 1;
			--j;
		}
		if (j==0 && digits[0]>=10)
		{
			vector<int>res_vec(digits.size() + 1, 0);
			for (int i = 0; i < digits.size();++i)
			{
				res_vec[i + 1] = digits[i];
			}
			res_vec[1] -= 10;
			res_vec[0] = 1;
			return res_vec;
		}
		else
		{
			return digits;
		}
	}
	
}
