/*
   Distinct Subsequences
   题意理解复杂了 distinct 只要选取的下标不一样就算 不考虑字符串重复
   */
#include "header.h"

class Solution
{
	public:
		int numDistinct(string S, string T)
		{
			int dp[T.length() + 1];
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;

			for (int i = 0; i < S.length(); i++)
				for (int j = T.length() - 1; j >= 0; j--)
					if (S[i] == T[j])
						dp[j + 1] += dp[j];

			return dp[T.length()];
		}

};

int main()
{
	Solution s;
	cout << s.numDistinct("rabbbit", "rabbit") << endl;

	return 0;
}
