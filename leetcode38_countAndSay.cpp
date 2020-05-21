#include "include.h"
/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ¡Ü n ¡Ü 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:
Input: 1
Output: "1"

Example 2:
Input: 4
Output: "1211"
*/
string countAndSay(int n)
{
	string current_str("1");
	for (n; n > 1; --n)
	{
		string next_str;
		int i = 0;
		int j = 0;
		while (j < current_str.size())
		{
			if (current_str[j] == current_str[i])
			{
				++j;
			}
			else
			{
				next_str += to_string(j - i) + string(1, current_str[i]);
				i = j;
			}
		}
		if (j == current_str.size())
		{
			next_str += to_string(j - i) + string(1, current_str[i]);
		}
		current_str = next_str;
	}
	return current_str;
}