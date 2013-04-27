/*
   ZigZag Conversion
   */
#include <iostream>
using namespace std;

class Solution 
{
	public:
		string convert(string s, int nRows) 
		{
			if (nRows == 1) return s;

			int diff = nRows + nRows - 2;
			
			string ret = "";

			for (int i = 0; i < nRows; i++)
			{
				for (int id = i; id < s.length(); id += diff)
				{
					ret.append(1, s[id]);
					int k = id + diff - 2 * i;
					if (i != 0 && i != nRows - 1 && k < s.length())
						ret.append(1, s[k]);
						//ret[top++] = s[k];
						//ret += s.substr(k, 1);
				}
			}
			return ret;
		}
};

int main()
{
	Solution s;
	cout << s.convert("ABCD", 1) << endl;
	cout << s.convert("PAYPALISHIRING", 3) << endl;

	return 0;
}
