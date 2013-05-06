/*
   Integer to Roman
   */
#include <iostream>
using namespace std;

class Solution
{
	public:
		string intToRoman(int num)
		{
			int a[] = { 1000,   900, 500, 400,  100,  90,  50, 40,   10,  9,    5,    4,   1};
			string r[] = {"M", "CM", "D", "CD", "C", "XC", "L","XL","X", "IX","V", "IV", "I"};
			string ret = "";

			for (int i = 0; num > 0 && i < 13; i++)
			{
				int k = num / a[i];
				num -= k * a[i];
				for (; k > 0; k--)
					ret.append(r[i]);
			}

			return ret;
		}
};

int main()
{
	Solution s;

	for (int i = 1; i < 11; i++)
		cout << s.intToRoman(i) << endl;

	cout << s.intToRoman(3999) << endl;

	return 0;
}

