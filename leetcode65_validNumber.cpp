#include "include.h"
bool isNumber(string s)
{
	if (s.empty())return true;
	map<char, vector<int>>char_indexsvec_map;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			continue;
		}
		else if (s[i] == 'e')
		{
			if (!char_indexsvec_map['e'].empty())
			{
				return false;
			}
			else
			{
				if (find_if(s.begin(), s.begin() + i, [](char bit){return bit >= '0' && bit <= '9'; }) == s.begin() + i)
				{
					return false;
				}
				if (find_if(s.begin() + i, s.end(), [](char bit){return bit >= '0' && bit <= '9'; }) == s.end())
				{
					return false;
				}
			}
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			if (i > 0 && s[i - 1] != ' ' && s[i - 1] != 'e')
			{
				return false;
			}
		}
		else if (s[i] == '.')
		{
			if (!char_indexsvec_map['.'].empty() || !char_indexsvec_map['e'].empty())
			{
				return false;
			}
			if (s.size() == 1)return false;
			if (i == 0 && !(s[i + 1] >= '0' && s[i + 1] <= '9'))return false;
			if (i == s.size() - 1 && !(s[i - 1] >= '0' && s[i - 1] <= '9'))return false;
			if (i > 0 && i < s.size() - 1 && !(s[i + 1] >= '0' && s[i + 1] <= '9') && !(s[i - 1] >= '0' && s[i - 1] <= '9'))return false;
		}
		else if (s[i] == ' ')
		{
			auto jud1 = find_if(s.begin(), s.begin() + i, [](char bit){return bit != ' '; });
			auto jud2 = find_if(s.begin() + i + 1, s.end(), [](char bit){return bit != ' '; });
			if (jud1 != s.begin() + i && jud2 != s.end())return false;
			if (jud1 == s.begin() + i && jud2 == s.end())return false;
		}
		else
		{
			return false;
		}
		char_indexsvec_map[s[i]].push_back(i);
	}
	return true;
}

