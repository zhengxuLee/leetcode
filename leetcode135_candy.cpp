#include "include.h"
//int candy(vector<int>& ratings) 
//{
//	if (ratings.empty())return 0;
//	int size = ratings.size();
//	vector<int>candies(size, 1);
//	while (true)
//	{
//		set<int>unsatisfied_index;
//		for (int i = 0; i < ratings.size(); ++i)
//		{
//			if (i == 0 && ratings[0]>ratings[1] && candies[0]<=candies[1])
//			{
//				unsatisfied_index.insert(0);
//			}
//			if (i>0 && i<size - 1)
//			{
//				if (ratings[i] > ratings[i - 1] &&candies[i]<=candies[i-1])unsatisfied_index.insert(i);
//				if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])unsatisfied_index.insert(i);
//			}
//			if (i == size - 1 && ratings[size - 1] > ratings[size - 2] && candies[size-1]<=candies[size-2])
//			{
//				unsatisfied_index.insert(size - 1);
//			}
//		}
//		if (unsatisfied_index.empty())
//			break;
//		for (auto index : unsatisfied_index)
//			++candies[index];
//	}
//	return accumulate(candies.begin(), candies.end(), (int)0);
//}


int candy(vector<int>& ratings)
{
	if (ratings.empty())return 0;
	int size = ratings.size();
	vector<int>candies(size, 1);
	for (int i = 1; i < size;++i)
	{
		if (ratings[i]>ratings[i-1] && candies[i]<=candies[i-1])
		{
			candies[i] = candies[i - 1] + 1;
		}
	}
	for (int j = size - 2; j >= 0;--j)
	{
		if (ratings[j] > ratings[j + 1] && candies[j]<=candies[j+1])
		{
			candies[j] = candies[j + 1] + 1;
		}
	}
	return accumulate(candies.begin(), candies.end(), (int)0);
}
