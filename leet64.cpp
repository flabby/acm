/*
   Minimum Path Sum
   */
#include "header.h"

class Solution
{
	public:
		int minPathSum(vector<vector<int> > &g)
		{
			int n = g.size();
			if (!n)
				return 0;
			int m = g[0].size();
			if (!m)
				return 0;

			int dp[n][m];
			dp[0][0] = g[0][0];

			for (int i = 1; i < m; i++)
				dp[0][i] = dp[0][i - 1] + g[0][i];

			for (int i = 1; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					if (j == 0)
						dp[i][j] = dp[i - 1][j] + g[i][j];
					else
						dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + g[i][j];
				}

			return dp[n - 1][m - 1];
		}
};
int main()
{
	vector<vector<int> > a;
	for (int i = 0; i < 3; i++)
	{
		vector<int> k;
		for (int j = 0; j < 3; j++)
			k.push_back(j);
		a.push_back(k);
	}

	Solution s;
	cout << s.minPathSum(a) << endl;

	return 0;
}
			
