#include "include.h"
/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"

*/


string fractionToDecimal(int numerator, int denominator)
{
	string res;
	if (denominator == 0)return res;
	long long llnumerator = numerator;
	long long lldenominator =denominator;
	int flag = llnumerator*lldenominator > 0 ? 1 : 0;
	llnumerator = abs(llnumerator);
	lldenominator = abs(lldenominator);
	long long mode = llnumerator / lldenominator;
	long long remaider = llnumerator - mode*lldenominator;
	res += to_string(mode);
	if (remaider!=0)res += ".";
	if (flag == 0)res.insert(res.begin(), '-');
	llnumerator = remaider * 10;

	unordered_map<int, pair<int, int>>numerator_mode_remaider;
	int repeat = 0;
	while (remaider != 0)
	{
		if (numerator_mode_remaider.find(llnumerator) != numerator_mode_remaider.end())
		{
			repeat = llnumerator;
			break;
		}
		mode = llnumerator / lldenominator;
		remaider = llnumerator - mode*lldenominator;
		res += to_string(mode);
		numerator_mode_remaider[llnumerator] = make_pair(mode, remaider);
		llnumerator = remaider * 10;
	}
	if (repeat == 0)
	{
		return res;
	}
	else
	{
		int count = 1;
		int current = repeat;
		while (10 * numerator_mode_remaider[current].second != repeat)
		{
			current = 10 * numerator_mode_remaider[current].second;
			++count;
		}
		res.push_back(')');
		size_t pos = res.size() - 1 - count;
		res.insert(pos, "(");
		return res;
	}
}
