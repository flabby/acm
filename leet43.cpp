/*
   Multiply Strings
   */
#include "header.h"

class Solution
{
	public:
		string multiply(string num1, string num2)
		{
			int len1 = num1.length();
			int len2 = num2.length();

			int* a = new int[len1 + len2];
//			memset(a, 0, sizeof(a));
			for (int i = 0; i < len1 + len2; i++)
				a[i] = 0;

			for (int i = len2 - 1; i >= 0; i--)
			{
				int carry = 0;
				for (int j = len1 - 1; j >= 0; j--)
				{
					int k = (num2[i] - '0') * (num1[j] - '0') + carry + a[i + j + 1];
					a[i + j + 1] = k % 10;
					carry = k / 10;
				}
				a[i] = carry;
			}
//			printf ("(");
//			for (int i = 0; i < len1 + len2; i++)
//				printf ("%d", a[i]);
//			puts (")");

			string ret = "";
			for (int i = 0; i < len1 + len2; i++)
				if (ret != "" || a[i] != 0)
					ret.append(1, (char)(a[i] + '0'));

//			cout << "ret=(" << ret << ")\n";
//			delete[] a;
			return ret == "" ? ret = "0" : ret;
		}
};

int main()
{
	Solution s;
	//cout << (123 * 55) << endl;
	cout << s.multiply("0", "0") << endl;
	cout << s.multiply("123", "55") << endl;
	cout << s.multiply("2", "3") << endl;
	cout << s.multiply("98", "9") << endl;

	return 0;
}
