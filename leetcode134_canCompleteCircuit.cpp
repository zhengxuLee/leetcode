#include "include.h"
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
	for (int start_index = 0; start_index < gas.size(); ++start_index)
	{
		int i = start_index;
		int amount = 0;
		for (i;i<gas.size()+start_index;++i)
		{
			amount += i >= gas.size() ? gas[i - gas.size()] : gas[i];
			amount -= i>=cost.size() ? cost[i - cost.size()] : cost[i];
			if (amount < 0)
				break;	
		}
		if (i==gas.size()+start_index && amount>=0)
		{
			return start_index;
		}
	}
	return -1;
}