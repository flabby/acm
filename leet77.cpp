/*
   Combinations
 */
#include "header.h"

class Solution
{
	public:
		vector<vector<int> > combine(int n, int k)
		{
			vector<vector<int> > ret;
			vector<int>a(k);

			bool flg[n + 1];
			memset(flg, 0, sizeof(flg));
			dfs(ret, a, n, k, flg, 0, 0);

			return ret;
		}

		void dfs(vector<vector<int> >&ret, vector<int> &a, int n, int k, bool flg[], int id, int dep)
		{
			if (dep == k)
			{
				ret.push_back(a);
				return;
			}

			for (int i = id; i < n; i++)
				if (!flg[i])
				{
					flg[i] = true;
					a[dep] = i + 1;
					dfs(ret, a, n, k, flg, i + 1, dep + 1);
					flg[i] = false;
				}
		}
};

int main()
{
	vector<vector<int> >ret;
	Solution s;
	ret = s.combine(4, 2);

	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
			printf ("%d ", ret[i][j]);
		puts ("");
	}

	return 0;
}
