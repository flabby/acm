/*
   Permutation Sequence
   */
#include "header.h"

class Solution
{
	public:
		string getPermutation(int n, int k)
		{
			int cnt = 1;
			for (int i = 2; i < n; i++)
				cnt *= i;

			int* flg = new int[n + 1];
			for (int i = 1; i <= n; i++)
				flg[i] = 0;

			string ret;
			for (int i = n - 1; i >= 0; i--)
			{
				int a = (k - 1) / cnt + 1;
				int id = getNum(flg, n, a);
				flg[id] = 1;
				ret.append(1, (char)id + '0');

				if (i == 0) break;
				k -= (a - 1) * cnt;
				cnt /= i;
			}

			return ret;
		}
		int getNum(int flg[], int n, int a)
		{
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				if (!flg[i])
					cnt++;
				if (cnt == a)
					return i;
			}
		}

};

int main()
{
	Solution s;
	cout << s.getPermutation(3, 1) << endl;
//	cout << s.getPermutation(3, 5) << endl;
//	cout << s.getPermutation(3, 6) << endl;
//	cout << s.getPermutation(3, 3) << endl;

	return 0;
}
