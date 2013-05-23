/*
   Add Binary
   */
#include "header.h"

class Solution
{
	public:
		string addBinary(string a, string b)
		{
			string ret;
			if (a.empty())
				return b;
			if (b.empty())
				return a;

			int i = a.length() - 1;
			int j = b.length() - 1;
			int carry = 0;

			while (i >= 0 || j >= 0)
			{
				int x(0), y(0);
				if (i >= 0)
				{
					x = a[i] - '0';
					i--;
				}
				if (j >= 0)
				{
					y = b[j] - '0';
					j--;
				}

				int k = carry + x + y;
				carry = k / 2;
				ret.append(1, (char)k % 2 + '0');
			}
			if (carry)
				ret.append(1, (char)carry + '0');
			cout << "ret (" << ret << ")\n";

			reverse(ret.begin(), ret.end());
			return ret;
		}
};

int main()
{
	Solution s;
	cout << s.addBinary("11", "1") << endl;

	return 0;
}
