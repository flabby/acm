/*
   Unique Paths
   */
#include "header.h"

class Solution
{
	public:
		int uniquePaths(int m, int n)
		{
			m--;
			n--;
			long long int ret = 1;
			int k = m + n;
			int x = m;
			if (m > n)
				x = n;

			for (int i = 1; i <= x; i++)
				ret = ret * (k - i + 1) / i;

			return ret;
		}
};

int main()
{
	Solution s;

	cout << s.uniquePaths(3, 7) << endl;

	return 0;
}
