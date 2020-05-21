#include "include.h"
int maxProfit2(vector<int>& prices, int start, int end)
{
	if (prices.empty() || start >= end)return 0;
	int buyPrice = 0;
	int sellPrice = 0;
	for (int i = start; i < end - 1; ++i)
	{
		if (prices[i + 1]>prices[i])
		{
			buyPrice = prices[i];
			for (int j = i + 1; j < prices.size(); ++j)
			{
				if (prices[j] >= prices[j + 1] || j == prices.size() - 1)
				{
					sellPrice = prices[j];
					return sellPrice - buyPrice + maxProfit2(prices, j + 1, end);
				}
			}
		}
	}
	return 0;
}
int maxProfit2(vector<int>& prices)
{
	if (prices.empty())return 0;
	return maxProfit2(prices, 0, prices.size() - 1);
}


int maxProfit22(vector<int>& prices)
{
	int aResult = 0;
	for (int i = 1; i<prices.size(); i++) {
		int aNet = prices[i] - prices[i - 1];
		if (aNet > 0) { aResult += aNet; }
	}
	return aResult;
}