/*
   Longest common Prefix
   */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
	public:
		string longestCommonPrefix(vector<string> &str)
		{
			if (str.size() == 0) return "";

			int len = str[0].length();
			for (int i = 0; i < str[0].length(); i++)
			{
				char ch = str[0][i];

				
				int flg = false;
				for (int j = 1; j < str.size(); j++)
					if (i >= str[j].length() || ch != str[j][i])
					{
						flg = true;	
						break;
					}

				//cout << "i=" << i << " ch=" << ch << " flg=" << flg << " len=" << len << endl;

				if (flg)
				{
					len = i;
					break;
				}
			}

			return str[0].substr(0, len);
		}
};

int main()
{
	Solution s;
	vector<string> a;
	a.push_back("aaaaa");
	a.push_back("aabbb");
	a.push_back("abbbb");

	cout << s.longestCommonPrefix(a) << endl;

	return 0;
}

