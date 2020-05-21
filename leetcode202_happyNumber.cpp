#include "include.h"

/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
Those numbers for which this process ends in 1 are happy numbers.

Example:
Input: 19
Output: true

Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

bool isValid(int n)
{
	if (n == 1)return true;
	if (n<10)return false;
	return n % 10 == 0 && isValid(n / 10);
}
bool isHappy(int n)
{
	unordered_set<int>loop_set = { n };
	while (1)
	{
		int sum = 0;
		while (n>0)
		{
			int last = n % 10;
			sum += last*last;
			n = n / 10;
		}
		if (isValid(sum))return true;
		if (loop_set.find(sum) == loop_set.end())
		{
			loop_set.insert(sum);
			n = sum;
		}
		else return false;
	}
}

