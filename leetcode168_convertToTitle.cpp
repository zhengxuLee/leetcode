#include "include.h"
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example :
1->A
2->B
3->C
...
26->Z
27->AA
28->AB
...
Example 1:
Input : 1
Output : "A"

Example 2 :
Input : 28
Output : "AB"

Example 3 :
Input : 701
Output : "ZY"

*/

string convertToTitle(int n)
{
	string res;
	stack<char>myStack;
	while (n > 26)
	{
		int r = n % 26;
		if (r == 0)
		{
			r = 26;
			n = n / 26 - 1;
		}
		else
		{
			n = n / 26;
		}
		myStack.push('A' + r - 1);
	}
	myStack.push('A' + n - 1);
	while (!myStack.empty())
	{
		char c = myStack.top();
		res.push_back(c);
		myStack.pop();
	}
	return res;
}