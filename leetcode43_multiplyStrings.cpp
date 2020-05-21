#include "include.h"
/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

Note:
The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
string multiply(string num1, string num2)
{
	string result;
	if (num1.empty() || num2.empty())return result;
	if (num1 == "0" || num2 == "0")return "0";
	int length1 = num1.size();
	int length2 = num2.size();
	vector<int>res_tmp(length1 + length2, 0);//¿¼ÂÇ½øÎ»
	for (int i = 0; i < length1; ++i)
	{
		for (int j = 0; j < length2; ++j)
		{
			int product = (num1[i] - '0')*(num2[j] - '0');
			res_tmp[i + j + 1] += product;
		}
	}
	for (int k = res_tmp.size() - 1; k > 0; --k)
	{
		if (res_tmp[k] >= 10)
		{
			res_tmp[k - 1] += res_tmp[k] / 10;
			res_tmp[k] = res_tmp[k] %10;
			
		}
	}
	int i = 0;
	while (res_tmp[i] == 0)++i;
	for (i; i < res_tmp.size();++i)
	{
		result += to_string(res_tmp[i]);
	}
	return result;
}
