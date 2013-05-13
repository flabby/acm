/*
   Minimum Window Substring
   O(n)
   */
#include "header.h"

const int MAXCHAR = 130;
class Solution
{
	public:
		string minWindow(string S, string T)
		{
			int cnt[MAXCHAR];
			int need[MAXCHAR];
			int sLen = S.length();
			int tLen = T.length();

			memset(need, 0, sizeof(need));
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < tLen; i++)
				need[T[i]]++;

			int mn = sLen + 1;
			int mnBegin = -1;
			int tot = 0;
			for (int begin = 0, end = 0; end < sLen; end++)
			{
				if (need[S[end]] == 0) continue;

				cnt[S[end]]++;
				if (cnt[S[end]] <= need[S[end]])
					tot++;

				if (tot == tLen)
				{
					while (need[S[begin]] == 0 
							|| cnt[S[begin]] > need[S[begin]])
					{
						if (cnt[S[begin]] > need[S[begin]])
							cnt[S[begin]]--;
						begin++;
					}	

					int kLen = end - begin + 1;
					if (kLen < mn)
					{
						mn = kLen;
						mnBegin = begin;
					}
				}
			}

			string ret = "";
			if (mnBegin > -1)
				ret = S.substr(mnBegin, mn);

			return ret;
		}
};

int main()
{
	Solution s;
	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;

	return 0;
}

