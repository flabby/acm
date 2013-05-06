/*
   3 sum
   */
#include <iostream>
#include <vector>
using namespace std;

#include <cstdio>
#include <algorithm>
#include <map>

class Solution
{
	public:
		vector<vector<int> > threeSum(vector<int> &num)
		{
			vector<vector<int> > ret;
			if (num.size() < 3) return ret;

			sort(num.begin(), num.end());
			vector<int> a;

			map<int, int> mp;
			for (int i = 0; i < num.size(); i++)
				if (mp.find(num[i]) == mp.end())
				{
					mp[num[i]] = 1;
					a.push_back(num[i]);
				}
				else
					mp[num[i]]++;
			
	//		map<int, int>::iterator it;
	//		for (it = mp.begin(); it != mp.end(); it++)
	//			printf ("(%d, %d)\n", it->first, it->second);

			for (int i = 0; i < a.size(); i++)
			{
				if (a[i] >= 0) break;

				int j = i + 1;
				if (mp[a[i]] > 1)
					j = i;
				for (; j < a.size(); j++)
				{
					if (-(a[i] + a[j]) < a[j]) break;

					vector<int>t;
					if (a[j] == -(a[i] + a[j]) && mp[a[j]] > 1)
					{	
						t.push_back(a[i]);
						t.push_back(a[j]);
						t.push_back(a[j]);
						ret.push_back(t);
					}
					else if (a[j] < -a[i] - a[j] && mp.find(-a[i]-a[j]) != mp.end())
					{
						t.push_back(a[i]);
						t.push_back(a[j]);
						t.push_back(-(a[i] + a[j]));
						ret.push_back(t);
					}
				}
			}

			if (mp[0] > 2)
			{
				vector<int> t;
				t.push_back(0);
				t.push_back(0);
				t.push_back(0);
				ret.push_back(t);
			}

	//		pr(ret);
			return ret;
		}
		void pr(vector<vector<int> > &a)
		{
			for (int i = 0; i < a.size(); i++)
				printf ("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
		}
};

int main()
{
	Solution s;

	vector<int> a;
	a.push_back(-1);
	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(-1);
	a.push_back(-4);
	a.push_back(0);
	a.push_back(0);
	a.push_back(1);

	s.threeSum(a);

	return 0;
}
