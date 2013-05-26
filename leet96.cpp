/*
   Unique Binary Search Trees
   */
#include "header.h"

class Solution
{
	public:
		int numTrees(int n)
		{
			if (!n) return 0;

			long long int ret = 1;
			for (int i = 1; i <= n; i++)
				ret = ret * (2 * n - i + 1) / i;

			ret /= n + 1;
			return ret;
		}
};

int main()
{
	Solution s;
	cout << s.numTrees(3) << endl;

	return 0;
}
