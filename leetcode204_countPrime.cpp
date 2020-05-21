#include "include.h"

/*'
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/

int countPrimes(int n)
{
	if (n < 2)return 0;
	int count = 0;
	vector<int>isPrime(n, 1);
	isPrime[0] = 0; isPrime[1] = 0;
	for (int i = 2; i*i < n; ++i)
	{
		if (isPrime[i] == 0)continue;
		for (int j = i*i; j < n; j = j + i)
		{
			isPrime[j] = 0;
		}
	}
	for (auto num : isPrime)
	{
		count += num == 1;
	}
	return count;
}