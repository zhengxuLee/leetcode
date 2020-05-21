#include "include.h"
int lengthOfLastWord(string s) 
{
	if (s.empty())return 0;
	int length = s.length();
	int last = length - 1;
	while (last>=0 && s[last]==' ')
	{
		--last;
	}
	int first = last;
	for (first; first >= 0;--first)
	{
		if (s[first]==' ')break;
	}
	return first==0 && s[0]!=' ' ? last+1 : last-first;
}