/*
   Spiral Matrix II
   */
#include "header.h"

class Solution
{
	public:
		vector<vector<int> > generateMatrix(int n)
		{
			vector<vector<int> > ret;
			for (int i = 0; i < n; i++)
			{
				vector<int>tmp(n);
				ret.push_back(tmp);
			}

			int st = 0;
			int ed = n - 1;
			int cnt = 0;
			while (st <= ed)
			{
				if (st == ed)
				{
					ret[st][st] = ++cnt;
					break;
				}
				for (int i = 0; i < ed - st; i++)
				{
					ret[st][st + i] = ++cnt;
	//				printf ("st=%d st+i=%d cnt=%d\n", st, st+i, cnt);
				}
				for (int i = 0; i < ed - st; i++)
				{
					ret[st + i][ed] = ++cnt;
	//				printf ("st+i=%d ed=%d cnt=%d\n", st+i, ed, cnt);
				}
				for (int i = 0; i < ed - st; i++)
				{
					ret[n - st - 1][ed - i] = ++cnt;
	//				printf ("n-st-1=%d ed-i=%d cnt=%d\n", n-st-1, ed-i, cnt);
				}
				for (int i = 0; i < ed - st; i++)
				{
					ret[n - st - 1 - i][st] = ++cnt;
	//				printf ("n-st-1-i=%d st=%d cnt=%d\n", n-st-1-i, st, cnt);
				}
	//			printf ("st=%d ed=%d n=%d\n", st, ed, n);

				st++;
				ed--;
			}

			return ret;
		}
};

int main()
{
	Solution s;
	vector<vector<int> > ret;
	ret = s.generateMatrix(4);

	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
			printf ("%2d ", ret[i][j]);
		puts ("");
	}

	return 0;
}
