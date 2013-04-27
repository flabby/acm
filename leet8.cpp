/*
  String to Integer (atoi)
  */
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

#include <limits.h>

class Solution
{
public:
	int atoi(const char *str) 
	{
		long long int ret = 0;

		const char *p = str;

		while (*p == ' ' && *p != '\0')
			p++;
		if (*p == '\0')
			return ret;
		
		//cout << "*p=(" << *p << ")\n";

		int sign = 1;
		if (*p == '-' || *p == '+')
		{
			if (*p == '-')
				sign = -1;
			p++;
		}

		while (*p != '\0')
		{
			if (*p < '0' || *p > '9')
				break;	
			ret *= 10;
			ret += (int)(*p - '0');

			p++;
	//		cout << " ret=" << ret << " ch=" << ch << endl;
		}

		ret *= sign;
		if (ret < INT_MIN)
			ret = INT_MIN;
		if (ret > INT_MAX)
			ret = INT_MAX;

		return (int)ret;
	}
};

int main()
{
	Solution s;
	cout << s.atoi("-123456") << endl;
	cout << s.atoi("  +0") << endl;
	cout << s.atoi("  +123") << endl;
	cout << s.atoi("  -123x88x") << endl;
	cout << s.atoi("2147483647") << endl;
	cout << s.atoi("3147483647") << endl;

	return 0;
}

