#include "include.h"

vector<string> wordBreak2(string s, vector<string>& wordDict) 
{
	vector<string>res_words;
	if (s.empty())return res_words;
	if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
	{
		res_words.push_back(s);
	}
	for (int i = 1; i < s.size();++i)
	{
		string s1 = s.substr(0, i);
		string s2 = s.substr(i);
		if (find(wordDict.begin(),wordDict.end(),s1)!=wordDict.end())
		{
			vector<string>sub_solution = wordBreak2(s2, wordDict);
			for (auto solu:sub_solution)
			{
				string str = s1 + string(" ") + solu;
				res_words.push_back(str);
			}
		}
	}
	return res_words;
}

