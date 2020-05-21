#include "include.h"

bool duplicate(int numbers[], int length, int* duplication)
{
	int i = 0;
	while (i < length)
	{
		if (numbers[i] != i)
		{
			if (numbers[i] < i)
			{
				*duplication = numbers[i];
				return true;
			}
			else
				swap(numbers[numbers[i]], numbers[i]);
		}
		else
			++i;
	}
	return false;
}
int main()
{
	int a[] = { 2, 3, 1, 0, 2, 5, 3 };
	int d = 0;
	cout << duplicate(a,7,&d);
	system("pause");
	return 0;
}