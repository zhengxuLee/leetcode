#include "include.h"

/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
The knight has an initial health point represented by a positive integer. 
If at any point his health point drops to 0 or below, he dies immediately.
Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

*/

int calculateMinimumHP(vector<vector<int>>& dungeon) 
{
	if (dungeon.empty())return 0;
	vector<vector<int>>dungeon_dp(dungeon.size(), vector<int>(dungeon[0].size(), 0));
	dungeon_dp.back().back() = dungeon.back().back() >= 0 ? 1 : 1 - dungeon.back().back();
	for (int i = dungeon.size() - 1; i >= 0; --i)
	{
		for (int j = dungeon[0].size() - 1; j >= 0; --j)
		{
			if (i + 1 <= dungeon.size() - 1 && j + 1 <= dungeon[0].size() - 1)
			{
				dungeon_dp[i][j] = max(max(min(dungeon_dp[i + 1][j], dungeon_dp[i][j + 1]), 0) - dungeon[i][j], 1);
			}
			else
			{
				if (i + 1 <= dungeon.size() - 1)
				{
					dungeon_dp[i][j] = max(max(dungeon_dp[i + 1][j], 0) - dungeon[i][j], 1);
				}
				if (j + 1 <= dungeon[0].size() - 1)
				{
					dungeon_dp[i][j] = max(max(dungeon_dp[i][j + 1], 0) - dungeon[i][j], 1);
				}
			}
		}
	}
	return dungeon_dp[0][0];
}