#include "include.h"
/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
*/
int largestRectangleArea1(vector<int>& heights) {

	int maxArea = 0;
	stack<int>stack1;
	heights.push_back(0);
	for (int i = 0; i<heights.size(); ++i)
	{
		if (stack1.empty())
			stack1.push(i);
		else
		{
			if (heights[i]>heights[stack1.top()])
			{
				stack1.push(i);
			}
			else
			{
				while (!stack1.empty())
				{
					int top = stack1.top();
					if (heights[top] > heights[i])
					{
						stack1.pop();
						int area = 0;
						if (!stack1.empty())
							area = (i - stack1.top() - 1)*heights[top];
						else
							area = (i)*heights[top];
						maxArea = max(maxArea, area);
					}
					else
						break;
				}
				stack1.push(i);
			}
		}
	}
	return maxArea;
}


int largestRectangleArea2(vector<int>& heights)
{
	if (heights.empty())return 0;
	int res_area = 0;
	for (int i = 0; i < heights.size();++i)
	{
		int left = i;
		int right = i;
		while (left >= 0)
		{
			if (heights[left] >= heights[i])
			{
				--left;
			}
			else
				break;
		}
		left = heights[left] < heights[i]?left:-1;
		while (right<heights.size())
		{
			if (heights[right] >= heights[i])
			{
				++right;
			}
			else
				break;
		}
		right = heights[right] < heights[i] ? right : heights.size();
		res_area = max(res_area, (right - left - 1)*heights[i]);
	}
	return res_area;
}
