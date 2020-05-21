#include "include.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
	if (nums2.empty())return;
	for (int i = 0; i < n;++i)
	{
		auto itr = upper_bound(nums1.begin(), nums1.begin()+m, nums2[i]);
		if (itr == nums1.begin() + m)
		{
			copy(nums2.begin()+i, nums2.end(), itr);
			break;
		}
		else
		{
			auto itr2 = nums1.begin() + m-1;
			for (; itr2 >= itr; --itr2)
			{
				*(itr2 + 1) = *itr2;
			}
			*itr = nums2[i];
			++m;
		}
	}
}
