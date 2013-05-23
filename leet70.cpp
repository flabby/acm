/*
	Climbing Stairs
	*/
#include "header.h"

class Solution
{
	public:
		int climbStairs(int n)
		{
			if (n < 2)
				return 1;

			int a = 1;
			int b = 1;

			for (int i = 2; i <= n; i++)
			{
				int c = a + b;
				a = b;
				b = c;
			}

			return b;
		}
};

int main()
{
	Solution s;
	cout << s.climbStairs(3) << endl;

	return 0;
}

