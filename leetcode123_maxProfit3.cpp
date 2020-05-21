#include "include.h"
//得到的是局部最优解，不是全局的
//int maxProfit3(vector<int>& prices) 
//{
//	if (prices.size() < 2)return 0;
//	//查找两个最大的上升区间
//	vector<int>candidates;
//	for (int i = 0; i < prices.size();)
//	{
//		int j = i + 1;
//		if (prices[j] <= prices[i])
//		{
//			++i;
//			continue;
//		}
//		while (j<prices.size() && prices[j]>prices[j-1])
//		{
//			++j;
//		}
//		candidates.push_back(prices[j - 1] - prices[i]);
//		i = j;
//	}
//	if (candidates.empty())return 0;
//	if (candidates.size() == 1)return candidates[0];
//	int max1 = INT_MIN;
//	int max2 = INT_MIN;
//	for (int i = 0; i < candidates.size();++i)
//	{
//		int tmp = max1;
//		max1 = max(max1, candidates[i]);
//		max2 = (tmp + candidates[i] + max2) - max1 - min(max2, candidates[i]);
//	}
//	return max1 + max2;
//}


int maxProfit3(vector<int>& prices)
{
	if (prices.size() < 2)return 0;
	vector<int>profit(prices.size(), 0);
	int chance = 2;
	for (int i = 1; i < prices.size(); ++i)
	{
		profit[i] = profit[i - 1];
		if (chance>0)
		{
			for (int j = 0; j < i; ++j)
			{
				int candidate = profit[j] + prices[i] - prices[j];
				profit[i] = max(profit[i], candidate);
			}
		}
		if (profit[i] != profit[i - 1])
		{
			--chance;
		}
	}
	return profit.back();
}

