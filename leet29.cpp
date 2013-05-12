/*
   Divide Two Integers
   */
#include "header.h"

class Solution
{
	public:
		int divide(int dividend, int divisor)
		{
			lint x = abs((lint)dividend);
			lint y = abs((lint)divisor);

			lint ret = 0;
			while (x >= y)
			{
				lint z = y;
				for (int i = 0; x >= z; i++)
				{
					x -= z;
					ret += (1 << i);

					z <<= 1;
				}
			}

			return ((dividend ^ divisor) >> 31) ? (-ret) : ret;
		}
};

int main()
{
//	for (int i = -4; i < 5; i++)
//		printf ("%d / 2 = %d\n", i, i / 2);
//
//	for (int i = -4; i < 6; i++)
//		printf ("%d / -2 = %d\n", i, i / -2);


	Solution s;

	cout << s.divide(1, 2) << endl;
	cout << s.divide(3, 2) << endl;
	cout << s.divide(-3, 2) << endl;

	return 0;
}
