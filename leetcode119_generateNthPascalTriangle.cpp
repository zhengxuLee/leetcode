#include "include.h"
//类似于节省空间的动态规划
vector<int> getRow(int rowIndex) 
{
	if (rowIndex < 0)return vector<int>();
	vector<int>res_nthRow(rowIndex+1, 1);
	if (rowIndex < 2)return res_nthRow;
	for (int i = 2; i <= rowIndex;++i)
	{
		for (int j = i-1; j >=1;--j)
		{
			res_nthRow[j] += res_nthRow[j - 1];
		}
	}
	return res_nthRow;
}