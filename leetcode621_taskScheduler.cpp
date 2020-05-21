#include "include.h"
/*
Given a char array representing tasks CPU need to do. 

It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order.

Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, 

there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.



Example:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

*/

int leastInterval(vector<char>& tasks, int n)
{
	vector<int>count(26, 0);
	for (int i = 0; i<tasks.size(); ++i)
	{
		++count[tasks[i] - 'A'];
	}
	sort(count.begin(), count.end());
	int time = 0;
	while (count[25]>0)
	{
		int i = 0;
		while (i <= n)
		{
			if (count[25] == 0)
				break;
			if (i<26 && count[25 - i]>0)
				count[25 - i]--;
			time++;
			i++;
		}
		sort(count.begin(), count.end());
	}
	return time;

}