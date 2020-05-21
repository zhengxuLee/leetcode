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
	int result = 0;				//ȫ������Ϊ��Чλ
	for (int i = 0; i < 32; i++)
	{
		result <<= 1;			//����һλ���ڳ�λ��
		result += (n & 1);		//ȡn�����һλ�ӵ����н����
		n >>= 1;
	}
	return result;
}