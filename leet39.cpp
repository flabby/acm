/*
   Combination Sum
 */
#include "header.h"

class Solution
{
	public:
		vector<vector<int> > combinationSum(vector<int> &candidates, int target)
		{
			int len = candidates.size();
			sort (candidates.begin(), candidates.end());
//			pr(candidates);

			vector<vector<int> > ret;
			vector<int> sl(len);
			dfs(ret, sl, candidates, 0, target);
			
//			cout << "ret size=" << ret.size() << endl;
//			for (int i = 0; i < ret.size(); i++)
//				pr(ret[i]);

			return ret;
		}

		void dfs(vector<vector<int> > &ret, vector<int> &sl, vector<int> &candidates, int dep, int rem)
		{
			if (dep >= candidates.size() || rem <= 0)
			{
				if (rem == 0)
				{
//					cout << "rem == 0" << endl;
					vector<int> tmp;
					for (int i = 0; i < dep; i++)
						for (int j = 0; j < sl[i]; j++)
							tmp.push_back(candidates[i]);
					ret.push_back(tmp);
//					pr(sl);
				}
				return;
			}

			int cnt = rem / candidates[dep];
//			printf ("cnt=%d rem=%d can[dep=%d]=%d\n", cnt, rem, dep, candidates[dep]);

			for (int i = 0; i <= cnt; i++)
			{
				sl[dep] = i;
				if (rem < i * candidates[dep])
					break;
				dfs(ret, sl, candidates, dep + 1, rem - i * candidates[dep]);
			}
		}
		void pr(vector<int> &a)
		{
			for (int i = 0; i < a.size(); i++)
				printf ("%d ", a[i]);
			printf ("\n\n");
			char ch;
			scanf ("%c", &ch);
		}

};

int main()
{
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(6);
	a.push_back(7);


	Solution s;
	s.combinationSum(a, 7);

	return 0;
}
