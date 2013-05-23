/*
   Unique Pahts II
   */
#include "header.h"

class Solution
{
	public:
		int uniquePathsWithObstacles(vector<vector<int> > &g)
		{
			int n = g.size();
			if (!n)
				return 0;
			int m = g[0].size();
			if (!m)
				return 0;
			
			int dp[n][m];
			memset(dp, 0, sizeof(dp));
			dp[0][0] = (!g[0][0]);
			for (int i = 1; i < m; i++)
				dp[0][i] = (!g[0][i] && dp[0][i - 1]);

			for (int i = 1; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					if (g[i][j])
						dp[i][j] = 0;
					else
					{
						if (j == 0)
							dp[i][j] = dp[i - 1][j];
						else
							dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
					}
				}

			return dp[n - 1][m - 1];
		}
};

int main()
{
	vector<vector<int> >a;
	for (int i = 0; i < 3; i++)
	{
		vector<int> k;
		for (int j = 0; j < 3; j++)
			k.push_back(0);
		a.push_back(k);
	}
	//a[1][1] = 1;
	Solution s;
	cout << s.uniquePathsWithObstacles(a) << endl;

	return 0;
}
