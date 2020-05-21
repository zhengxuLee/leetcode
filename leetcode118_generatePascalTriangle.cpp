#include "include.h"

vector<vector<int>> generate(int numRows) 
{
	vector<vector<int>> res_pascalTriangle;
	if (numRows < 1)return res_pascalTriangle;
	for (int i = 1; i <= numRows;++i)
	{
		vector<int>nth_row(i, 1);
		for (int j = 1; j < i - 1; ++j)
		{
			nth_row[j] = res_pascalTriangle.back()[j - 1] + res_pascalTriangle.back()[j];
		}
		res_pascalTriangle.push_back(nth_row);
	}
	return res_pascalTriangle;
}