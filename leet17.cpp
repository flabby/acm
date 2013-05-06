/*
   Letter Combinations of a Phone Number
   */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<string> letterCombinations(string digits) 
		{
			string s[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
			vector<string> ret;
			
			//cout << "begin  digits=(" << digits << ")\n";

			dfs(s, digits, ret, "");

		//	pr(ret);
			return ret;
		}
		
		void dfs(string s[], string digits, vector<string> &ret, string r)
		{
			if (digits == "")
			{
				ret.push_back(r);
				return;
			}

			//cout << "digits=(" << digits << ") r=(" << r << ")\n";

			int d = (int)digits[0] - '0';
			for (int i = 0; i < s[d].length(); i++)
				dfs(s, digits.substr(1, digits.length() - 1), ret, r + s[d].substr(i, 1)); 
		}

		void pr(vector<string> &a)
		{
			for (int i = 0; i < a.size(); i++)
				cout << a[i] << " ";
			cout << "\n";
		}

};

int main()
{
	Solution s;
	s.letterCombinations("23");

	return 0;
}

