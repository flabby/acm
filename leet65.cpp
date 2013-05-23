/*
   Valid Nubmer
   */
#include "header.h"

// error solution1 
lass Solution1
{
	public:
		bool isNumber(const char *s)
		{
			if (s == NULL) return false;

			while(isspace(*s)) s++;

			bool eFlg(0);
			bool dotFlg(0);
			bool spaceFlg(0);
			bool firstFlg(0);
			bool secondFlg(0);

			while (*s != '\0')
			{
				if (*s == '.')
				{
					if (dotFlg || eFlg || spaceFlg) return false;
					else dotFlg = true;
				}
				else if (*s == 'e')
				{
					if (!firstFlg || eFlg || spaceFlg) return false;
					else eFlg = true;
				}
				else if (isdigit(*s))
				{
					if (spaceFlg) return false;
					if (!eFlg) firstFlg = true;
					else secondFlg = true;
				}
				else if (*s == '+' || *s == '-')
				{
					if (spaceFlg) return false;
					if (!eFlg || !(*(s - 1) == 'e')) return false;
				}
				else if (isspace(*s)) spaceFlg = true;
				else return false;
				s++;
			}

			if (!firstFlg) return false;
			else if (eFlg && !secondFlg) return false;
			else return true;
		}
};
// ok solution 0
class Solution0 
{
	bool dotFlg;
	bool numFlg;
	bool eFlg;
	public:
		bool isNumber(const char *ss)
		{
			int len = strlen(ss);
			char* s = new char [len + 1];
			
			for (int i = 0; i <= len; i++)
				s[i] = ss[i];

			//printf ("len=%d s=(%s)\n", len, s);

			int i;
			for (i = len - 1; i >= 0 && ss[i] == ' '; i--);
			s[i + 1] = '\0';

			//printf ("s=(%s)\n", s);

			if (*s == '\0')
				return false;

			while (*s == ' ')
				*s++;

			if (getNum(s))
				return true;
			else if (numFlg && *s == 'e')
			{
				s++;
				if (getNum(s) && numFlg && !dotFlg)
					return true;
				while (*s == ' ') s++;
				return numFlg && !dotFlg && *s == '\0';
			}
			else
				return false;
		}

		bool getNum(char *&p)
		{
			dotFlg = false;
			numFlg = false;
			if (*p == '+' || *p == '-')
				*p++;

			if (*p == '.' && !dotFlg)
			{
				dotFlg = true;
				*p++;
			}
			
			if (*p < '0' || *p > '9')
				return false;

			while (*p >= '0' && *p <= '9')
			{
				p++;
				numFlg = true;
			}


			if (!dotFlg && *p == '.')
			{
				*p++;
				dotFlg = true;
			}

			if (numFlg && *p == '\0')
				return true;
			else if (*p < '0' || *p > '9')
				return false;

			while (*p >= '0' && *p <= '9')
			{
				p++;
				numFlg = true;
			}

			return numFlg && *p == '\0';
		}
};

int main()
{
	Solution s;
//	cout << s.isNumber("2e10") << endl;
//	cout << s.isNumber("   ") << endl;
//	cout << s.isNumber("  1.20 ") << endl;
//	cout << s.isNumber("  -1.20 ") << endl;
//	cout << s.isNumber("  2e.3 ") << endl;
	cout << s.isNumber("  1. ") << endl;
	cout << s.isNumber("  1.2      a") << endl;

	return 0;
}

			

