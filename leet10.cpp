/*
   Regular Expression Matching
   */
#include <iostream>
using namespace std;

#include <cstdio>

class Solution {
	public:
		bool isMatch(const char *s, const char *p)
		{
//			printf ("s=(%s) p=(%s)\n", s, p);
			
			if (*p == '\0') 
				return *s == '\0';

			//next char is not '*'
			if (*(p + 1) != '*')
				return (*p == *s || (*p == '.' && *s != '\0')) 
						&& isMatch(s + 1, p + 1);
			//next char is '*'	
			while (*p == *s || (*p == '.' && *s != '\0'))
			{
				if (isMatch(s, p + 2))
					return true;
				s++;
			}

			return isMatch(s, p + 2);
		}
};

int main()
{
	Solution s;

	cout << s.isMatch("aab", "c*a*b") << endl;

	return 0;
}
