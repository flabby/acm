/*
   Decode Ways
   问题分析不准确 出现0 必须和它前一个数字组合 不可能以0开始
   */
#include "header.h"

class Solution
{
	public:
		int numDecodings(string s)
		{
			int len = s.length();
			if (!len)
				return 0;

			int dp[len + 1];
			dp[0] = 1;

			for (int i = 1; i <= len; i++)
			{
				int c1 = 0;
				if (s[i-1] != '0')
					c1 = dp[i-1];

				int c2 = 0;
				if (i >= 2 && (s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6'))
					c2 = dp[i - 2];
				dp[i] = c1 + c2;
			}
			return dp[len];
		}
};

int main()
{
	Solution s;
//	cout << s.numDecodings("12") << endl;
//	cout << s.numDecodings("123") << endl;
	cout << s.numDecodings("26") << endl;
	cout << s.numDecodings("101010") << endl;

	return 0;
}
