#include "include.h"
/*

All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T
for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC", "CCCCCAAAAA"]
*/


vector<string> findRepeatedDnaSequences(string s)
{
	vector<string>res_str;
	set<string>res_set;
	if (s.size() < 10)return res_str;
	unordered_set<string>hash_set;
	for (int i = 0; i <= s.size() - 10; ++i)
	{
		string str = s.substr(i, 10);
		if (hash_set.find(str) != hash_set.end())
		{
			res_set.insert(str);
		}
		else
		{
			hash_set.insert(str);
		}
	}
	copy(res_set.begin(), res_set.end(), back_inserter(res_str));
	return res_str;
}