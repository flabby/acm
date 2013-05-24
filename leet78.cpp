/*
   Subsets
   */
#include "header.h"

class Solution
{
	public:
		vector<vector<int> > subsets(vector<int> &S)
		{
			int n = S.size();
			vector<vector<int> >ret;

			if (!n) return ret;
			
			sort(S.begin(), S.end());
			bool flg[n];
			memset(flg, 0, sizeof(flg));
			dfs(ret, S, flg, 0, n);

			return ret;
		}

		void dfs(vector<vector<int> > &ret, vector<int> &S, bool flg[], int dep, int n)
		{
			if (dep == n)
			{
				vector<int>a;
				for (int i = 0; i < n; i++)
					if (flg[i])
						a.push_back(S[i]);
				ret.push_back(a);
				return;
			}

			flg[dep] = true;
			dfs(ret, S, flg, dep + 1, n);
			flg[dep] = false;

			dfs(ret, S, flg, dep + 1, n);
		}

};

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	vector<vector<int> >ret;
	Solution s;
	ret = s.subsets(a);
	prMat(ret);

	return 0;
}
