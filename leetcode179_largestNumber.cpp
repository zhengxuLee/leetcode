#include "include.h"
/*
Given a list of non negative integers, arrange them such that they form the largest number.
Example 1:
Input : [10, 2]
Output : "210"

Example 2 :
Input : [3, 30, 34, 5, 9]
Output : "9534330"
Note : The result may be very large, so you need to return a string instead of an integer.
*/
static bool strSort(const string& str1, const string& str2)
{
	if (str1.empty() || str2.empty())return false;
	int length = min(str1.length(), str2.length());
	for (int i = 0; i < length; ++i)
	{
		if (str1[i]<str2[i])return true;
		if (str1[i]>str2[i])return false;
	}
	string tmp1 = str1 + str2;
	string tmp2 = str2 + str1;
	return tmp1 < tmp2;
}

string largestNumber(vector<int>& nums)
{
	string largestNumber;
	if (nums.empty())return largestNumber;
	if (count(nums.begin(), nums.end(), 0) == nums.size())return "0";
	vector<string>numberStrings;
	for (auto num : nums)
	{
		numberStrings.push_back(to_string(num));
	}
	sort(numberStrings.begin(), numberStrings.end(), strSort);
	for (int i = numberStrings.size() - 1; i >= 0; --i)
	{
		largestNumber += numberStrings[i];
	}
	return largestNumber;
}
