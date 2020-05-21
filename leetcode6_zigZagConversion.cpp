#include "include.h"
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

string convert(string s, int numRows) 
{
	string res;
	if (s.empty())return res;
	vector<vector<char>> matrix;
	for (int i = 0; i < numRows;++i)
	{
		vector<char>row;
		matrix.push_back(row);
	}
	int count = 0;
	while (count != s.size())
	{
		for (int i = 0; i < numRows; ++i)
		{
			matrix[i].push_back(s[count]);
			++count;
		}
		for (int j = numRows - 2; j>0; --j)
		{
			matrix[j].push_back(s[count]);
			++count;
		}
	}
	for (auto vec:matrix)
	{
		for (auto c:vec)
		{
			res.push_back(c);
		}
	}
	return res;
}

