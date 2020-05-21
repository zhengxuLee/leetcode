#include "include.h"
/*
Given a collection of intervals, merge all overlapping intervals.
Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
*/
struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
bool interval_cmp(const Interval& range1, const Interval& range2)
{
	return range1.start < range2.start;
}
vector<Interval> merge1(vector<Interval>& intervals)
{
	vector<Interval>merged_ranges;
	sort(intervals.begin(), intervals.end(), interval_cmp);
	for (int i = 0; i < intervals.size(); ++i)
	{
		if (merged_ranges.empty())
		{
			merged_ranges.push_back(intervals[i]);
		}
		else
		{
			Interval last = merged_ranges.back();
			if (intervals[i].end <= last.end)
			{
				continue;
			}
			else if (intervals[i].start <= last.end)
			{
				merged_ranges.back().end = intervals[i].end;
			}
			else
			{
				merged_ranges.push_back(intervals[i]);
			}
		}
	}
	return merged_ranges;
}
vector<Interval> merge2(vector<Interval>& intervals)
{
	vector<Interval>res;
	if (intervals.empty())return res;
	sort(intervals.begin(), intervals.end(), interval_cmp);
	Interval current = intervals[0];
	for (int i = 0; i < intervals.size(); ++i)
	{
		if (intervals[i].start <= current.end)
		{
			current.end = max(current.end, intervals[i].end);
		}
		else
		{
			res.push_back(current);
			current = intervals[i];
		}
	}
	res.push_back(current);
	return res;
}
//
//bool start_cmp(const Interval& range1, const Interval& range2)
//{
//	return range1.start < range2.start;
//}
//
//vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
//{
//	auto it = std::lower_bound(intervals.begin(), intervals.end(), newInterval, start_cmp);
//	intervals.insert(it, newInterval);
//	vector<Interval> ret = { intervals.front() };
//	for (auto interval : intervals)
//	{
//		Interval back = ret.back();
//		if (interval.start<=back.end)
//		{
//			ret.back().end = max(back.end, interval.end);
//		}
//		else
//		{
//			ret.push_back(interval);
//		}
//	}
//	return ret;
//}
