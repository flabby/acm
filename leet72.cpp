/*
   Edit Distance
   */
#include "header.h"

class Solution 
{
	public:
		int minDistance(string w1, string w2)
		{
			int len1 = w1.length();
			int len2 = w2.length();
			int dp[len1 + 1][len2 + 2];

			for (int i = 0; i <= len1; i++)
				dp[i][0] = i;

			for (int i = 0; i <= len2; i++)
				dp[0][i] = i;

			for (int i = 1; i <= len1; i++)
				for (int j = 1; j <= len2; j++)
				{
					if (w1[i - 1] == w2[j - 1])
						dp[i][j] = dp[i - 1][j - 1];
					else
						dp[i][j] = min(dp[i - 1][j - 1] + 1, min(
									dp[i][j - 1] + 1, dp[i - 1][j] + 1));
				}
			
//			for (int i = 0; i <= len1; i++)
//			{
//				for (int j = 0; j <= len2; j++)
//					printf ("%d ", dp[i][j]);
//				puts ("");
//			}

			return dp[len1][len2];
		}
};

int main()
{
	Solution s;
	cout << s.minDistance("abcd", "bbc") << endl;

	return 0;
}

							
