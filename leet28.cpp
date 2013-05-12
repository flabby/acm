/*
   Implement strStr()
   */
#include "header.h"

class Solution
{
	public:
		char *strStr(char *hayStack, char *needle) 
		{
			int lena = strlen(needle);
			int lenb = strlen(hayStack);

	//		cout << "lena=" << lena << endl;
	//		cout << "lenb=" << lenb << endl;

			char *ret = NULL;

			if (lena == 0)
				return hayStack;

			for (char *p = hayStack; *p; p++)
			{
	//			cout << "here\n";

				int j = 0;
				for (; j < lena; j++)
					if (p[j] != needle[j])
						break;
				if (j == lena)
				{
					ret = p; 
					break;
				}
			}

	//		cout << (ret == NULL) << endl;

			return ret;
		}
};

int main()
{
	Solution s;

//	cout << s.strStr("", "a") << endl;
	cout << s.strStr("abcdabcdabab", "abab") << endl;

	return 0;
}

