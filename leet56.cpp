/*
   Merge Intervals
   */
#include "header.h"

bool cmp(const Interval& lhs, const Interval& rhs)
{
	if (lhs.start == rhs.start)
		return lhs.end < rhs.end;
	return lhs.start < rhs.start;
}
class Solution
{
	public:
		vector<Interval> merge(vector<Interval> &intervals)
		{
			vector<Interval>ret;
			int len = intervals.size();
			if (!len)
				return ret;

			sort(intervals.begin(), intervals.end(), cmp);

			int x = intervals[0].start;
			int y = intervals[0].end;
			for (int i = 1; i < len; i++)
			{
				if (intervals[i].start <= y)
					y = max(y, intervals[i].end);
				else
				{
					ret.push_back(Interval(x, y));
					x = intervals[i].start;
					y = intervals[i].end;
				}
			}
			ret.push_back(Interval(x, y));

			return ret;
		}
};

int main()
{
	vector<Interval>a;
	a.push_back(Interval(1, 3));
	a.push_back(Interval(2, 6));
	a.push_back(Interval(8, 10));
	a.push_back(Interval(15, 18));

	Solution s;
	vector<Interval>ret;
	ret = s.merge(a);

	for (int i = 0; i < ret.size(); i++)
		ret[i].pr();

	return 0;
}
