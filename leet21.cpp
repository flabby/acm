/*
   Generate Parentheses
   */
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<string> generateParenthesis(int n)
		{
			vector<string> ans;

			gen(ans, "", 0, 0, n);
			return ans;
		}

		void gen(vector<string> &ans, string str, int l, int r, int n)
		{
			if (l == n)
			{
				ans.push_back(str.append(n - r, ')'));
				return;
			}

			gen(ans, str + "(", l + 1, r, n);
			if (l > r)
				gen(ans, str + ")", l, r + 1, n);
		}
};

void pr(vector<string> &a)
{
	puts ("-----------------");
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	puts ("--------------------------");
}

int main()
{
	Solution s;

	vector<string> a = s.generateParenthesis(3);
	pr(a);

	//pr(s.generateParenthesis(3));
	return 0;
}

