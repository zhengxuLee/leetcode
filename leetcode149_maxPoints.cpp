#include "include.h"
struct Position {
	int x;
	int y;
	Position() : x(0), y(0) {}
	Position(int a, int b) : x(a), y(b) {}
};
//通过一个点，最多有多少条斜率相同的直线
int gcd(int num1, int num2)
{
	if (num2 == 0)
		return num1;
	else
		return gcd(num2, num1%num2);
}

int maxPoints(vector<Position>& points)
{
	if (points.size() < 3)return points.size();
	unordered_map<string, int>lineNumMap;
	unordered_map<double, int>xNumMap;
	int max_Line = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		lineNumMap.clear();
		xNumMap.clear();
		int dupli = 1;
		for (int j = i + 1; j < points.size(); ++j)
		{
			if (points[j].x == points[i].x && points[j].y == points[i].y)
			{
				dupli++;
				continue;
			}
			if (points[j].x == points[i].x)
			{
				xNumMap[points[j].x]++;
			}
			else
			{
				int _gcd = gcd(points[j].y - points[i].y, points[j].x - points[i].x);
				string key = to_string((points[j].y - points[i].y) / _gcd) + "+" + to_string((points[j].x - points[i].x) / _gcd);
				lineNumMap[key]++;
			}
		}
		max_Line = max(max_Line, dupli);
		for (auto tmp1 : lineNumMap)
		{
			max_Line = max(max_Line, tmp1.second + dupli);
		}
		for (auto tmp2 : xNumMap)
		{
			max_Line = max(max_Line, tmp2.second + dupli);
		}
	}
	return max_Line;
}