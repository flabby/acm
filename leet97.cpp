/*
   Interleaving String
   */
#include "header.h"

const int MAXN = 110;
class Solution 
{
	int dp[MAXN][MAXN];
	public:
		bool isInterleave(string s1, string s2, string s3)
		{
			int len1 = s1.length();
			int len2 = s2.length();
			int len3 = s3.length();
			if (len1 + len2 != len3) return false;

			memset(dp, -1, sizeof(dp));
			return dfs(s1, s2, s3, 0, 0);
		}
		bool dfs(string &s1, string &s2, string &s3, int i, int j)
		{
			if (dp[i][j] > -1)
				return dp[i][j];

			if (i == s1.length() && j == s2.length())
				return dp[i][j] = 1;
			
			if ((i < s1.length() && s1[i] == s3[i+j] && dfs(s1, s2, s3, i + 1, j))
					|| (j < s2.length() && s2[j] == s3[i+j] && dfs(s1,s2,s3,i, j+1)))
				return dp[i][j] = 1;
			return dp[i][j] = 0;
		}
};

class Solution1 
{
	public:
		bool isInterleave(string s1, string s2, string s3)
		{
			if (s1.length() + s2.length() != s3.length())
				return false;

			return dfs(s1, s2, s3, 0, 0);
		}

		bool dfs(string &s1, string &s2, string &s3, int i, int j)
		{
			if (i == s1.length() && j == s2.length())
				return true;

			if ((i < s1.length() && s1[i] == s3[i + j] && dfs(s1, s2, s3, i+1, j))
					|| (j < s2.length() && s2[j] == s3[i + j] && dfs(s1, s2, s3, i, j+1)))
				return true;
			return false;
		}
};

int main()
{
	Solution s;
	cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;

	return 0;
}

				
