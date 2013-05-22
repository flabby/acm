/*
   Length of Last Word
   */
#include "header.h"

class Solution 
{
	public:
		int lengthOfLastWord(const char *s)
		{
			const char *p = s;

			int ret = 0;
			int ans = 0;

			while ((ret = getNext(p)) != 0)
			{
			//	printf ("ret=%d p=(%s)\n", ret, p);
				ans = ret;
			}

			return ans;
		}
		int getNext(const char *&p)
		{
			int ret = 0;
			while (*p == ' ')
				p++;

			for (; *p != ' ' && *p != '\0'; p++, ret++);

			return ret;
		}
};

int main()
{
	Solution s;
	cout << s.lengthOfLastWord("Hello World") << endl;
	cout << s.lengthOfLastWord("HelloWorld") << endl;

	return 0;
}
