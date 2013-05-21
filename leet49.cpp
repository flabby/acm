/*
   Anagrams 
   change chars' position word 变位词
   */

#include "header.h"

class Solution
{
	public:
		vector<string> anagrams(vector<string> &strs)
		{
			vector<string>ret;

			map<string, vector<int> >mp;
			map<string, vector<int> >::iterator it;

			for (int i = 0; i < strs.size(); i++)
			{
				string st(strs[i]);
				sort(st.begin(), st.end());
				mp[st].push_back(i);
			}

			for (it = mp.begin(); it != mp.end(); it++)
				if ( (it->second).size() > 1)
				{
					for (int i = 0; i < (it->second).size(); i++)
						ret.push_back(strs.at((it->second)[i]));
				}

			for (int i = 0; i < ret.size(); i++)
				cout << ret[i] << endl;

			return ret;
		}
};

int main()
{
	vector<string> a;
	a.push_back("abcde");
	a.push_back("accce");
	a.push_back("bcade");
	a.push_back("bbade");

	Solution s;
	s.anagrams(a);

	return 0;
}

