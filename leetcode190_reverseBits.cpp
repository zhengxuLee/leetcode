#include "include.h"
#include <stdint.h>
/*
Reverse bits of a given 32 bits unsigned integer.

Example:
Input: 43261596
Output: 964176192
Explanation: 43261596 represented in binary as 00000010100101000001111010011100,
return 964176192 represented in binary as 00111001011110000010100101000000.

*/

uint32_t reverseBits(uint32_t n)
{
	if (n == 0)return 0;
	int result = 0;				//全部设置为无效位
	for (int i = 0; i < 32; i++)
	{
		result <<= 1;			//左移一位，腾出位置
		result += (n & 1);		//取n的最后一位加到现有结果上
		n >>= 1;
	}
	return result;
}