#include "include.h"
/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:
Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]*/
int maxProfit1(vector<int>& prices)
{
	if (prices.size() < 2)return 0;
	int size = prices.size();
	vector<int>hold(size, 0);
	vector<int>sold(size, 0);
	vector<int>rst(size, 0);
	rst[0] = 0;
	hold[0] = -prices[0];
	sold[0] = 0;
	for (int i = 1; i < size; ++i)
	{
		hold[i] = max(hold[i - 1], rst[i - 1] - prices[i]);
		sold[i] = hold[i - 1] + prices[i];
		rst[i] = max(rst[i - 1], sold[i - 1]);
	}
	return max(sold[size - 1], rst[size - 1]);
}

int maxProfit(vector<int>& prices)
{
	if (prices.size() < 2)return 0;
	int rst = 0;
	int hold = INT_MIN;
	int sold = 0;
	for (int i = 0; i < prices.size(); ++i)
	{
		int preSold = sold;
		sold = hold + prices[i];
		hold = max(hold, rst - prices[i]);
		rst = max(rst, preSold);
	}
	return max(rst, sold);
}

