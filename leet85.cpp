/*
   Maximal Rectangle
   */
#include "header.h"

class Solution
{
	public:
		int maximalRectangle(vector<vector<char> >&g)
		{
			int n = g.size();
			if (!n) return 0;
			int m = g[0].size();
			if (!m) return 0;
			

			vector<int> H(m);
			vector<int> L(m);
			vector<int> R(m, m);

			int ret = 0;
			for (int i = 0; i < n; i++)
			{
				int left = 0, right = m;
				for (int j = 0; j < m; j++)
					if (g[i][j] == '1')
					{
						H[j]++;
						L[j] = max(L[j], left);
					}
					else
					{
						left = j + 1;
						H[j] = 0; L[j] = 0; R[j] = m;
					}

				for (int j = m - 1; j >= 0; j--)
					if (g[i][j] == '1')
					{
						R[j] = min(R[j], right);
						ret = max(ret, H[j] * (R[j] - L[j]));
					}
					else
						right = j;
			}

			//printf ("n=%d m=%d\n", n, m);
			return ret;
		}
};

char s[][10] = {
	"0010011",
	"1011101",
	"1111101",
	"0111010"};

char s1[][10] = {
	"1111",
	"1111",
	"1111"};

int main()
{
	vector<vector<char> >g;

	for (int i = 0; i < 3; i++)
	{
		vector<char> k;
		for (int j = 0; j < 4; j++)
			k.push_back(s1[i][j]);
		g.push_back(k);
	}

	Solution s;
	cout << s.maximalRectangle(g) << endl;

	return 0;
}
