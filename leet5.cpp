/*
   Longest Palindromic Substring
   */
#include <iostream>
using namespace std;

class Solution 
{
	public:
		string preProcess(string s)
		{
			if (!s.length()) return "^$";

			string ret = "^";
			for (int i = 0; i < s.length(); i++)
				ret += "#" + s.substr(i, 1);
			ret += "#%";
			return ret;
		}

		string longestPalindrome(string s) {
			string T = preProcess(s);
			int n = T.length();

			int *p = new int[n];

			int C = 0, R = 0;

			for (int i = 1; i < n - 1; i++)
			{
				int i_m = 2 * C - i;

				p[i] = (R > i) ? min(R - i, p[i_m]) : 0;

				while (T[i + 1 + p[i]] == T[i - 1 - p[i]])
					p[i]++;

				if (i + p[i] > R)
				{
					C = i;
					R = i + p[i];
				}
			}

			int mx = 0;
			int id = 0;
			for (int i = 1; i < n - 1; i++)
				if (p[i] > mx)
				{
					mx = p[i];
					id = i;
				}

			delete[] p;

			return s.substr((id - 1 - mx) / 2, mx);
		}
};

int main()
{
	Solution S;

	cout << S.longestPalindrome("ababa") << endl;
	cout << S.longestPalindrome("aaaaab") << endl;

	return 0;
}

