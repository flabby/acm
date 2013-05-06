/*
   4 sum
bug1: ret duplicate
   */
#include <iostream>
#include <vector>
using namespace std;

#include <algorithm>
#include <cstdio>
#include <map>

class Solution
{
	public:
		bool isEqual(vector<int> &a, vector<int> &b)
		{
			for (int i = 0; i < a.size(); i++)
				if (a[i] != b[i])
					return false;
			return true;
		}

		vector<vector<int> > fourSum(vector<int> &num, int target)
		{
			vector<vector<int> > ret;

			if (num.size() < 4)
				return ret;

			sort (num.begin(), num.end());

			for (int i = 0; i < num.size() - 3; i++)
				for (int j = i + 1; j < num.size() - 2; j++)
				{
					int x = target - num[i] - num[j];
					int l = j + 1;
					int r = num.size() - 1;
					while (l < r)
					{
						int k = num[l] + num[r];
						if (k == x)
						{
							vector<int> t;
							t.push_back(num[i]);
							t.push_back(num[j]);
							t.push_back(num[l]);
							t.push_back(num[r]);
							
							//printf ("ret.size()=%d num[%d]=%d num[%d]=%d num[%d]=%d num[%d]=%d\n", ret.size(), i, num[i], j, num[j], l, num[l], r, num[r]);
							if (!ret.size()
								|| !isEqual(ret.back(), t))
								ret.push_back(t);

							l++;
							r--;
						}
						else if (k < x)
							l++;
						else 
							r--;
					}
				}
			
			vector<vector<int> > ans;
			for (int i = 0; i < ret.size(); i++)
			{
				int flg = 1;
				for (int j = 0; j < i; j++)	
					if (isEqual(ret[i], ret[j]))
					{
						flg = 0;
						break;
					}
				if (flg)
					ans.push_back(ret[i]);
			}
//			pr(ret);
//			puts("--------");
//			pr(ans);
			return ans;
		}

		void pr(vector<vector<int> >a)
		{
			for (int i = 0; i < a.size(); i++)
			{
				for (int j = 0; j < a[i].size(); j++)
					printf ("%d ", a[i][j]);
				puts ("");
			}
		}

};

int main()
{
	Solution s;
	vector<int>a;
	a.push_back(2);
	a.push_back(0);
	a.push_back(3);
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	/*
	a.push_back(1);
	a.push_back(0);
	a.push_back(-1);
	a.push_back(0);
	a.push_back(-2);
	a.push_back(2);
*/
	s.fourSum(a, 7);

	return 0;
}

