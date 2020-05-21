#include "include.h"
bool isValidAlph(char c)
{
	if (c>='a' && c<='z')
		return true;
	if (c>='A' && c<='Z')
		return true;
	if (c>='0' && c<='9')
	{
		return true;
	}
	return false;
}
bool isPalindrome(string s) 
{
	if (s.empty())return true;
	int i = 0;
	int j = s.size() - 1;
	while (i<j)
	{
		while (i<j && !isValidAlph(s[i]))
			++i;
		
		while (i<j && !isValidAlph(s[j]))
			--j;
		
		s[i] = (s[i] >= 'a' && s[i] <= 'z') ? s[i] + 'A' - 'a' : s[i];
		s[j] = (s[j] >= 'a' && s[j] <= 'z') ? s[j] + 'A' - 'a' : s[i];
		if (s[i] == s[j])
		{
			++i;
			--j;
		}
		else
		{
			return false;
		}
	}
	return true;
}                  
