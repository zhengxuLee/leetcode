#include "include.h"

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.
Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
*/


//double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//{
//	int size1 = nums1.size();
//	int size2 = nums2.size();
//	int p1 = 0;
//	int p2 = 0;
//	vector<int>merge;
//	while (p1 < nums1.size() && p2 < nums2.size())
//	{
//		if (nums1[p1]<nums2[p2])
//		{
//			
//			merge.push_back(nums1[p1]);
//			++p1;
//		}
//		else if (nums1[p1]>nums2[p2])
//		{
//			
//			merge.push_back(nums2[p2]);
//			++p2;
//		}
//		else
//		{
//			
//			merge.push_back(nums1[p1]);
//			merge.push_back(nums2[p2]);
//			++p1;
//			++p2;
//		}
//	}
//	if (p1 == nums1.size())
//	{
//		copy(nums2.begin() + p2, nums2.end(), back_inserter(merge));
//	}
//	if (p2 == nums2.size())
//	{
//		copy(nums1.begin() + p1, nums1.end(), back_inserter(merge));
//	}
//	if ((size1 + size2) % 2 == 0)
//	{
//		return (merge[merge.size() / 2 - 1] + merge[merge.size() / 2]) / 2;
//	}
//	else
//	{
//		return merge[merge.size() / 2];
//	}
//
//}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int size1 = nums1.size();
	int size2 = nums2.size();
	int size = size1 + size2;
	if (size1 > size2)return findMedianSortedArrays(nums2, nums1);
	int k = (size1 + size2 + 1) / 2;
	int l = 0;
	int r = size1;
	int m1 = 0;
	int m2 = 0;
	while (l < r)
	{
		m1 = l + (r - l) / 2;
		m2 = k - m1;
		if (nums1[m1] < nums2[m2 - 1])
		{
			l = m1 + 1;
		}
		else
		{
			r = m1;
		}
	}
	m1 = l;
	m2 = k - m1;
	int c1 = max(m1 == 0 ? INT_MIN : nums1[m1 - 1], m2 == 0 ? INT_MIN : nums2[m2 - 1]);
	if (size % 2 == 1)
	{
		return c1;
	}
	int c2 = min(m1 == size1 ? INT_MAX : nums1[m1], m2 == size2 ? INT_MAX : nums2[m2]);
	return (c1 + c2) / (double)2;
}