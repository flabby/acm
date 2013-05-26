/*
   Restore Ip Address
   a.b.c.d   a 是单独的0 或者非0开头的数字组合 
   */
#include "header.h"

class Solution
{
	public:
		vector<string> restoreIpAddresses(string s)
		{
			vector<string>ret;
			vector<int>path;

			dfs(ret, path, s, 0, 0);
			return ret;
		}

		string itoa(int x)
		{
			string ret;
			bool first = true;
			while (first || x)
			{
				first = false;
				ret.append(1, (char)(x % 10 + '0'));
				x /= 10;
			}
			reverse(ret.begin(), ret.end());
			return ret;
		}
		void dfs(vector<string> &ret, vector<int> &path, string &s, int id, int dep)
		{
			if (s.length() - id > (4 - dep) * 3
					|| s.length() - id < 4 - dep)
				return;

			if (id == s.length() && dep == 4)
			{
				string k(itoa(path[0]));
				for (int i = 1; i < 4; i++)
				{
					k.append(1, '.');
					k.append(itoa(path[i]));
				}
				ret.push_back(k);
				return; 
			}

			int x = 0;
			for (int i = id; i < id + 3 && i < s.length(); i++)
			{
				x = x * 10 + s[i] - '0';
				if (x <= 255)
				{
					path.push_back(x);
					dfs(ret, path, s, i+1, dep + 1);
					path.pop_back();
				}
				if (x == 0)
					break;
			}
		}
};

int main()
{
	Solution s;
	vector<string> ret = s.restoreIpAddresses("25525511135");

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << endl;

	return 0;
}
