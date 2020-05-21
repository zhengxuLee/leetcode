#include "include.h"

int middleOfThree(int a, int b,int c)
{
	if (a<b)
	{
		if (b < c)return b;
		if (a < c)return c;
		return a;
	}
	else
	{
		if (a < c)return a;
		if (c < b)return b;
		return c;
	}
}

void quickSort(vector<int>&nums, int start, int end)
{
	if (nums.empty())return;
	if (end-start<=1)return;//[)的区间，长度为0或1时应该停止
	int p1 = start;
	int p2 = end;
	int middle = (start + end) / 2;
	int pivot = middleOfThree(nums[start], nums[middle], nums[end-1]);
	while (true)
	{
		while (nums[p1] <= pivot)
			++p1;
		--p2;
		while (pivot<=nums[p2])
			--p2;
		if (p1 < p2)
		{
			swap(nums[p1], nums[p2]);
			++p1;
		}
		else
		{
			break;
		}
	}
	quickSort(nums, start, p1);
	quickSort(nums, p1, end);
}

//int nth_element(vector<int>&nums, int nth)
//{
//	int first = 0;
//	int last = nums.size();
//	while (last-first>3)
//	{
//		int p1 = first;
//		int p2 = last;
//		int middle = (first + last) / 2;
//		int pivot = middleOfThree(nums[first], nums[middle], nums[last - 1]);
//		while (true)
//		{
//			while (nums[p1] <pivot)
//				++p1;
//			--p2;
//			while (pivot < nums[p2])
//				--p2;
//			if (p1 < p2)
//			{
//				swap(nums[p1], nums[p2]);
//				++p1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		if (p1 <= nth)
//		{
//			first = p1;
//		}
//		else
//		{
//			last = p1;
//		}
//	}
//	sort(nums.begin() + first, nums.begin() + last);
//
//}
