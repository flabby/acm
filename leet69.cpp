/*
   Sqrt(x)
   */
#include "header.h"

class Solution
{
	public:
		int sqrt(int x)
		{
			if (!x || x == 1)
				return x;

			long long int ret = 1;
			for (; ret * ret <= x; ret++);

			return ret - 1;
		}
};

int main()
{
	Solution s;
	cout << s.sqrt(1) << endl;
	cout << s.sqrt(4) << endl;
	cout << s.sqrt(5) << endl;
	cout << s.sqrt(9) << endl;

	return 0;
}
