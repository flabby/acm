/*
   Count and Say
   */
#include "header.h"

class Solution
{
	public:
		string countAndSay(int n)
		{
			string s = "1";

			for (int i = 1; i < n; i++)
			{
			//	cout << "i=" << i << " s=(" << s << ")\n";
				change(s);
			//	cout << endl;
			}

			return s;
		}

		void change(string &a)
		{
			string b;

			char pre = a[0];
			int cnt = 1;
			int len = a.length();
			for (int i = 1; i <= len; i++)
			{
				if (i == len || a[i] != pre)
				{
					b.append(1, (char)(cnt + '0'));
					b.append(1, pre);

					if (i < len)
						pre = a[i];
					cnt = 1;
			//		cout << " change i=" << i << " cnt=" << cnt << " b=(" << b << ")\n";
				}
				else
					cnt++;
			}

			a = b;
		}
};

int main()
{
	Solution s;
	cout << s.countAndSay(10) << endl;

	return 0;
}
