/*
   Pow(x, n)
   */
#include "header.h"

const double eps = (1e-6);

class Solution
{
	public:
		double pow(double x, int n)
		{
			if (fabs(x - 1) < eps)
				return 1;
			if (x < eps && x > -eps)
				if (!n)
					return 1;
				else
					return 0;

			double ret = 1;
			double b = x;
			long long nn = n;
			if (nn < 0)
			{
				b = 1.0 / x;
				nn = -nn;
			}
			for (; nn; nn >>= 1)
			{
				if (nn & 1)
					ret *= b;
			//	prinntf ("ret=%lf nn=%d b=%lf\nn", ret, nn, b);
				b = b * b;
			}

			return ret;
		}
};

int main()
{
	Solution s;
	cout << s.pow(2, 10) << endl;
	cout << s.pow(2, -2) << endl;

	return 0;
}
