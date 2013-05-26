/*
   Subsets II
   */
#include "header.h"

class Solution
{
	public:
		vector<vector<int> > subsetsWithDup(vector<int> &S)
		{
			vector<int> path;
			vector<vector<int> >ret;

			sort(S.begin(), S.end());
			dfs(ret, path, S, 0);

			return ret;
		}

		void dfs(vector<vector<int> >&ret, vector<int> &path, vector<int> &s, int id)
		{
			ret.push_back(path);

			for (int i = id; i < s.size(); i++)
			{
				if (i != id && s[i] == s[i - 1]) continue;

				path.push_back(s[i]);
				dfs(ret, path, s, i + 1);
				path.pop_back();
			}
		}
};

int main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(2);
	a.push_back(1);

	Solution s;
	vector<vector<int> >ret = s.subsetsWithDup(a);

	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
			printf ("%d ", ret[i][j]);
		printf ("\n");
	}

	return 0;
}
