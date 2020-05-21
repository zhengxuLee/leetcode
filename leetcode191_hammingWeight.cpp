#include "include.h"
#include <stdint.h>

/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:
Input: 11
Output: 3
Explanation: Integer 11 has binary representation 00000000000000000000000000001011

Example 2:
Input: 128
Output: 1
Explanation: Integer 128 has binary representation 00000000000000000000000010000000

*/

int hammingWeight(uint32_t n) {
	if (n == 0)return 0;
	int res = 0;
	for (int i = 0; i < 32; ++i)
	{
		res += n & 1;
		n >>= 1;
	}
	return res;
}