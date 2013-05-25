/*
   Scramble String
   */
#include "header.h"

const int MAXN = 110;
class Solution
{
	bool dp[MAXN][MAXN][MAXN];
	public:
		bool isScramble1(string s1, string s2)
		{
			int n = s1.length();
			if (!n || n != s2.length()) return false;

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dp[0][i][j] = (s1[i] == s2[j]);

			for (int len = 1; len < n; len++)
				for (int i = 0; i + len < n; i++)
					for (int j = 0; j + len < n; j++)
					{
						dp[len][i][j] = false;
						for (int k = 0; k < len; k++)
							if ((dp[k][i][j] && dp[len-k-1][i+k+1][j+k+1])
									|| (dp[k][i][j+len-k] && dp[len-k-1][i+1+k][j]))
							{
								dp[len][i][j] = true;
								break;
							}
					}
			pr(n);
			return dp[n-1][0][0];
		}
		bool isScramble(string s1, string s2)
		{
			int n = s1.length();
			if (!n || n != s2.length()) return false;

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dp[1][i][j] = (s1[i] == s2[j]);

			for (int len = 2; len <= n; len++)
				for (int i = 0; i + len <= n; i++)
					for (int j = 0; j + len <= n; j++)
					{
						dp[len][i][j] = false;
						for (int k = 1; k < len; k++)
							if ((dp[k][i][j] && dp[len-k][i+k][j+k])
									|| (dp[k][i][j+len-k] && dp[len-k][i+k][j]))
							{
								dp[len][i][j] = true;
								break;
							}
					}
			pr(n);
			return dp[n][0][0];
		}
		void pr(int n)
		{
			for (int k = 0; k <= n; k++)
			{
				printf ("len=%d\n", k);
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
						printf ("%d ", dp[k][i][j]);
					puts ("");
				}
				puts ("");
			}
		}
};

int main()
{
	Solution s;
	cout << s.isScramble("great", "rgtae") << endl;

	return 0;
}
						
