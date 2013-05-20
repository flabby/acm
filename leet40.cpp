/*
   Combination Sum II
   */
#include "header.h"

class Solution 
{
	public:
		vector<vector<int> > combinationSum2(vector<int> &num, int target)
		{
			map<int, int>mp;

			for (int i = 0; i < num.size(); i++)
				mp[num[i]]++;

			map<int, int>::iterator it;
//			for (it = mp.begin(); it != mp.end(); it++)
//				printf ("[%d -> %d]\n", it->first, it->second);

			int n = mp.size();
			int *a = new int[n + 1];
			int *cnt = new int[n + 1];
			int i = 0;
			for (it = mp.begin(); it != mp.end(); it++)
			{
				a[i] = it->first;
				cnt[i] = it->second;
				i++;
			}

//			printf ("n=%d\n", n);
//			for (int i = 0; i < n; i++)
//				printf ("a[%2d]=%2d cnt[%2d]=%2d\n", i, a[i], i, cnt[i]);

			vector<vector<int> >ret;
			vector<int>sol(n + 1);
			dfs(ret, sol, a, cnt, n, 0, target);

//			puts ("-----------ret-----------------");
//			for (int i = 0; i < ret.size(); i++)
//			{
//				for (int j = 0; j < ret[i].size(); j++)
//					printf ("%d -> ", ret[i][j]);
//				puts ("");
//			}
			return ret;
		}

		void dfs(vector<vector<int> > &ret, vector<int> &sol, int a[], int cnt[], int n, int dep, int tsum)
		{
			if (dep >= n || tsum <= 0)
			{
				if (tsum == 0)
				{
					vector<int>tmp;
					for (int i = 0; i < dep; i++)
						for (int j = 0; j < sol[i]; j++)
							tmp.push_back(a[i]);

					ret.push_back(tmp);
				}
				return;
			}

			int k = min(tsum / a[dep], cnt[dep]);

			for (int i = 0; i <= k; i++)
			{
				sol[dep] = i;
				dfs(ret, sol, a, cnt, n, dep + 1, tsum - i * a[dep]);
			}

		}
};

int main()
{
	vector<int>a;
	a.push_back(10);
	a.push_back(1);
	a.push_back(2);
	a.push_back(7);
	a.push_back(6);
	a.push_back(1);
	a.push_back(5);

	Solution s;
	s.combinationSum2(a, 8);
//	vector<vector<int> > ret = s.combinationSum2(a, 8);
//	for (int i = 0; i < ret.size(); i++)
//	{
//		for (int j = 0; j < ret[i].size(); j++)
//			printf ("%d -> ", ret[i][j]);
//		puts ("");
//	}

	return 0;
}
	
