/*
   Roman to Integer
   */
#include <iostream>
using namespace std;

#include <cstdio>

class Solution
{
	public:
	
		int getId(char ch)
		{
			char r[]= "IVXLCDM"; // 7 chars
			for (int i = 0; i < 7; i++)
				if (r[i] == ch)
					return i;
		}

		int romanToInt(string s)
		{
			int a[] = {1, 5, 10, 50, 100, 500, 1000};

			int ret = 0;
			int pre = 0;
			for (int i = 0; i < s.length(); i++)
			{
				int k = a[getId(s[i])]; 
			//	printf ("s[%d]=%c k=%d ret=%d pre=%d\n", i, s[i], k, ret, pre);
				if (i != 0 && k > pre)
				{
					ret += k - 2 * pre;
					pre = k;
				}
				else
				{
					ret += k;
					pre = k;
				}
			//	printf (" s[%d]=%c k=%d ret=%d pre=%d\n\n", i, s[i], k, ret, pre);
			}

			return ret;
		}
};

int main()
{
	Solution s;
	cout << s.romanToInt("MMMCMXCVIII") << endl;

	return 0;
}

					
