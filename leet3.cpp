/*
   leetcode 3 Longest Substring Without Repeating Characters
   */
#include <iostream>
using namespace std;
#include <string>

const int MAXN = 260;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			if (!s.length())
				return 0;

			int ret = 1;
			int k = 1;
			int st = 0;
			int pre[MAXN];
			for (int i = 0; i < MAXN; i++)
				pre[i] = -1;
			pre[s[0]] = 0;

			for (int i = 1; i < s.length(); i++)
			{
				if (pre[s[i]] < st)
				{
					pre[s[i]] = i;
					k++;
					ret = max(k, ret);
				}
				else
				{
					st = pre[s[i]] + 1;
					k = i - pre[s[i]];
					pre[s[i]] = i;
				}
			}
			return ret;
		}
};

int main()
{
	string str = "abcabcbb";
	Solution s;
	cout << s.lengthOfLongestSubstring(str) << endl;
	cout << s.lengthOfLongestSubstring("bbb") << endl;
	cout << s.lengthOfLongestSubstring("abcddcbae") << endl;
	cout << s.lengthOfLongestSubstring("abcbaebcdef") << endl;

	return 0;
}

