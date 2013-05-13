/*
   Substring with Concatenation of All Words
 */
#include "header.h"

class Solution1 {
	private:
		int count[1000];
		int countSize;
		map<string, int> index;
		vector<int> ret;
	public:
		vector<int> findSubstring(string S, vector<string> &L) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			ret.clear();
			if (L.size() == 0)
				return ret;

			index.clear();
			countSize = 0;
			for(int i = 0; i < L.size(); i++)
				if (index.count(L[i]) > 0)
					count[index[L[i]]]++;
				else
				{
					index[L[i]] = countSize;
					count[countSize++] = 1;
				}

			int step = L[0].size();

			vector<int> a;

			for(int i = 0; i < step; i++)
			{
				a.clear();
				for(int j = i; j < S.size(); j += step)
				{
					if (j + step <= S.size())
					{
						string s(S, j, step);
						if (index.count(s) > 0)
							a.push_back(index[s]);
						else
							a.push_back(-1);
					}
				}

				int beg = -1;
				int end = 0;
				int size = L.size();
				while(end < a.size())
				{
					if (a[end] != -1)
					{
						if (count[a[end]] > 0)
						{
							if (beg == -1)
								beg = end;
							size--;
							count[a[end]]--;
						}
						else
						{
							while(beg < end)
							{
								count[a[beg]]++;
								size++;
								if (a[beg++] == a[end])
									break;
							}
							count[a[end]]--;
							size--;
						}
					}
					else
					{
						size = L.size();
						if (beg != -1)
						{    
							for(int i = beg; i < end; i++)
								count[a[i]]++;
						}
						beg    = -1;
					}

					end++;

					if (size == 0)
					{
						ret.push_back(beg * step + i);
						size++;
						count[a[beg]]++;
						beg++;
					}
				}

				if (beg != -1)
				{
					for(int i = beg; i < end; i++)
						count[a[i]]++;
				}
			}

			return ret;
		}
};

class Solution
{
	public:
		vector<int> findSubstring(string S, vector<string> &L)
		{
			map<string, int>mp;
			map<string, int>::iterator it;
			map<string, int> cnt;

			vector<int>ret;

			for (int i = 0; i < L.size(); i++)
				mp[L[i]]++;

			//		for (it = mp.begin(); it != mp.end(); it++)
			//			printf ("%s -> %d\n", it->first.c_str(), it->second);

			int n = L.size();
			int m = L[0].length();

			for (int i = 0; i + n * m - 1 < S.length(); i++)
			{
				int j;
				cnt.clear();
				for (j = i; j < i + n * m; j += m)
				{
					string tmp = S.substr(j, m);
					if (mp.find(tmp) == mp.end())
						break;

					cnt[tmp]++;
					if (cnt[tmp] > mp[tmp])
						break;
				}

				if (j == i + n * m)
					ret.push_back(i);
			}

			//		for (int i = 0; i < ret.size(); i++)
			//			printf ("ret[%d]=%d\n", i, ret[i]);

			return ret;
		}
};

int main()
{
	Solution s;

	vector<string> L;
	L.push_back("foo");
	//L.push_back("foo");
	L.push_back("bar");

	vector<int> ret;
	ret = s.findSubstring("barfoothefoobarman", L);

	return 0;
}
