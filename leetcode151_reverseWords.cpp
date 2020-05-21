#include "include.h"
void reverseWords(string &s)
{
	if (s.empty())return;
	reverse(s.begin(), s.end());
	int i = 0;
	int j = 0;
	int end = 0;
	while (i < s.size())
	{
		while (i < s.size() && s[i] == ' ')
			++i;
		j = i;
		while (j < s.size() && s[j] != ' ')
			++j;
		reverse(s.begin() + i, s.begin() + j);
		if (end != 0 && i!=s.size())//���ҵ�һ����Ч�Ĵ������һ���ո�
		{
			s[end] = ' ';
			++ end;
		}
		copy(s.begin() + i, s.begin() + j, s.begin() + end);
		end += j - i;
		i = j + 1;
	}
	s.erase(s.begin() + end, s.end());
}
