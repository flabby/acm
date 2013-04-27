/*
   Reverse Integer
   */
#include <iostream>
using namespace std;

class Solution {
	public:
		int reverse(int x)
		{
			long long int ret = 0;
			while (x)
			{
				int k = x % 10;
			//	cout << " x=" << x << " k=" << k << endl << endl;
				x /= 10;

				ret *= 10;
				ret += k;
			}
			//cout << "ret=" << ret << " sign=" << sign << endl;
			return (int)ret;
		}
};

int main()
{	
	Solution s;
	cout << s.reverse(-123) << endl;
	cout << s.reverse(321) << endl;
	
	return 0;
}

