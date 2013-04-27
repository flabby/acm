/*
   Palindrome Number
  */
#include <iostream>
using namespace std;

class Solution
{
	public:
		bool isPalindrome(int x) 
		{
			if (x < 0) return false;

			int div = 1;
			while (x / div >= 10)
				div *= 10;

			while (x)
			{
				int l = x / div;
				int r = x % 10;
				
			//	cout << "l=" << l << " r=" << r << " x=" << x << endl;

				if (l != r) return false;
				x = x % div / 10;
				div /= 100;
			}

			return true;
		}
};

int main()
{
	Solution s;

	cout << s.isPalindrome(12321) << endl;
	cout << s.isPalindrome(1321) << endl;
	cout << s.isPalindrome(-123) << endl;

	return 0;
}

