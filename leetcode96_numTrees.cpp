#include "include.h"
/*Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
Example:
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:
1        3     3      2      1
\       /     /      / \      \
 3     2     1      1   3      2
/     /       \                 \
2     1         2                 3*/
//其实动态规划就可以了
int numTrees2(int n)
{
	if (n == 0 || n == 1)return 1;
	vector<int>dp(n + 1, 1);
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = 0;
		for (int j = 1; j <= i; ++j)
		{
			dp[i] += dp[j - 1] * dp[i - j];
		}
	}
	return dp[n];
}

map<string, int>dp_map;
int helper(int left, int right)
{
	string key = to_string(left) + to_string(right);
	if (left>right)
	{
		dp_map[key] = 0;
		return 0;
	}
	if (dp_map.find(key)==dp_map.end())
	{
		dp_map[key] = 0;
		for (int i = left; i <= right;++i)
		{
			int left_count = helper(left, i - 1);
			int right_count = helper(i + 1, right);
			if (left_count == 0)
			{
				if (right_count == 0)
					dp_map[key]++;
				else
					dp_map[key] += right_count;
			}
			else
			{
				if (right_count == 0)
					dp_map[key] += left_count;
				else
					dp_map[key] += left_count*right_count;
			}
		}
	}
	return dp_map[key];
}
int numTrees(int n) 
{
	if (n<1)
	{
		return 0;
	}
	return helper(1, n);
}

