#include "include.h"
/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Example 1:
Input: version1 = "0.1", version2 = "1.1"
Output: -1

Example 2:
Input: version1 = "1.0.1", version2 = "1"
Output: 1

Example 3:
Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
*/

class Solution {
public:
	queue<int>decodeVersion(string version)
	{
		int i = 0;
		queue<int>myQueue;
		while (i < version.size())
		{
			int j = i;
			while (j < version.size() && version[j] != '.')
			{
				++j;
			}
			string str = version.substr(i, j - i);
			int num = stoi(str);
			myQueue.push(num);
			i = j + 1;
		}
		return myQueue;
	}
	int compareVersion(string version1, string version2)
	{
		if (version1.empty() || version2.empty())return 0;
		queue<int>queue1 = decodeVersion(version1);
		queue<int>queue2 = decodeVersion(version2);
		while (!queue1.empty() && !queue2.empty())
		{
			int num1 = queue1.front();
			queue1.pop();
			int num2 = queue2.front();
			queue2.pop();
			if (num1<num2)return -1;
			if (num1>num2)return 1;
		}
		if (queue1.empty() && queue2.empty())return 0;
		while (!queue1.empty())
		{
			int num = queue1.front();
			queue1.pop();
			if (num > 0)return 1;
		}
		while (!queue2.empty())
		{
			int num = queue2.front();
			queue2.pop();
			if (num > 0)return -1;
		}
		return 0;
	}
};