/*
   Gray Code
   */
#include "header.h"

class Solution
{
	public:
		vector<int> grayCode(int n)
		{
			vector<int> ret;
			if (!n) 
			{
				ret.push_back(0);
				return ret;
			}

			bool flg[1<<n];
			memset(flg, 0, sizeof(flg));

			dfs(ret, flg, 0, n, (1<<n) - 1);

			return ret;
		}

		void dfs(vector<int> &ret, bool flg[], int x, int n, int cnt)
		{
			if (ret.size() == cnt)
				return;

			ret.push_back(x);
			flg[x] = true;

			for (int i = 0; i < n; i++)
			{
				int y;
				if ((x & (1<<i)) != 0)
					y = x & ~(1 << i);
				else
					y = x | (1 << i);

				if (!flg[y])
				{
					dfs(ret, flg, y, n, cnt - 1);
					return;
				}
			}
		}
};

int main()
{
	Solution s;
	vector<int> ret = s.grayCode(2);
	for (int i = 0; i < ret.size(); i++)
		printf ("%d ", ret[i]);
	
	return 0;
}
