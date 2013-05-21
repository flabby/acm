/*
   Wildcard Matching
   dp[i][j] = 
   1) false, not match
   2) (p[j] == '?' || s[i] == p[j]) && diagnal
   3) p[j] == '*' && (left || diagnal || dp[0..i-1][j])     
   */
#include "header.h"

class Solution 
{
	public:
		bool isMatch(const char *s, const char *p)
		{
			int lens = strlen(s);
			int lenp = strlen(p);

			if (lenp == 0)
				return lens == 0;

			int cnt = 0;
			for (int i = 0; i < lenp; i++)
				if (p[i] != '*')
					cnt++;

			if (cnt > lens)
				return false;

			bool dp[lenp + 1];

			dp[0] = (p[0] == '*');
			for (int i = 1; i < lenp; i++)
				dp[i] = (dp[i - 1] && p[i] == '*');

			for (int i = 0; i < lens; i++)
			{
				bool diagnal = false;
				if (i == 0)
					diagnal = true;

				bool left = false;
				for (int j = 0; j < lenp; j++)
				{
					bool k = (p[j] == '*' && (diagnal || left || dp[j]))
						|| ((p[j] == '?' || p[j] == s[i]) && diagnal);
					diagnal = dp[j];
					dp[j] = k;
					left = k;
				}
			}

			return dp[lenp - 1];
		}
};

int main()
{
	Solution s;

	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("aa", "*") << endl;
	cout << s.isMatch("aa", "?*") << endl;
	cout << s.isMatch("aab", "c*a*b") << endl;

	return 0;
}
