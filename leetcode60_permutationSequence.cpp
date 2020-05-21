#include "include.h"

void dfs(int n, int kth, int& k,vector<int>&partition_solu, vector<int>&kth_vec)
{
	if (partition_solu.size()==n)
	{
		++k;
		if (k==kth)
		{
			kth_vec.insert(kth_vec.begin(), partition_solu.begin(), partition_solu.end());
		}
		return;
	}
	if (k==kth)return;
	vector<int>candidates;
	for (int i = 1; i <= n;++i)
	{
		if (find(partition_solu.begin(),partition_solu.end(),i)==partition_solu.end())
		{
			candidates.push_back(i);
		}
	}
	for (int i = 0; i < candidates.size(); ++i)
	{
		partition_solu.push_back(candidates[i]);
		dfs(n, kth,k,partition_solu,kth_vec);
		partition_solu.pop_back();
	}
}

string getPermutation(int n, int k)
{
	string res_str;
	vector<int>partition_solu;
	vector<int>kth_vec;
	int init = 0;
	dfs(n, k,init, partition_solu, kth_vec);
	for (auto num : kth_vec)
	{
		res_str += to_string(num);
	}
	return res_str;
}
