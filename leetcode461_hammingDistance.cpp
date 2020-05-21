#include "include.h"

/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ¡Ü x, y < 231.

Example:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)

The above arrows point to positions where the corresponding bits are different.
*/

int hammingDistance(int x, int y)
{
	int xor1 = x^y;
	int count = 0;
	while (xor1 != 0)
	{
		if (xor1 & 1)++count;
		xor1 >>= 1;
	}
	return count;
}