/*
   Implement strStr()
   */
#include "header.h"

class Solution1
{
	public:
		char *strStr(char *T, char *P)
		{
		//	printf ("T=(%s) P=(%s)\n", T, P);

			int lenp = strlen(P);

			if (lenp == 0) return T;

		//	printf ("lenp=%d\n", lenp);

			vector<int> next(lenp + 1);
			getNext(next, P, lenp);

		//	printf ("here\n");

			for (int i = 0; i < lenp; i++)
				printf ("next[%d]=%d\n", i, next[i]);
			puts ("");

			for (int i = 0, j = 0; T[i]; )
			{
			//	printf ("P[%d]=%c T[i=%d]=%c\n", j, P[j], i, T[i]);
				if (j < 0 || P[j] == T[i]) i++, j++;
				else j = next[j];

			//	printf (" i=%d j=%d\n", i, j);

				if (j >= lenp)
				{
			//		printf (" ok i=%d\n", i);
					return T + i - j;
				}
			}

			return NULL;
		}

		void getNext(vector<int> &next, char *P, int lenp)
		{
			next[0] = -1;
			for (int i = 0, j = -1; i < lenp; )
			{
				if (j < 0 || P[j] == P[i]) next[++i] = ++j;
				else j = next[j];
			}
		}
};

class Solution
{
	public:
		char *strStr(char *T, char *P) 
		{
			int lenp = strlen(P);

			if (lenp == 0) return T;

			vector<int> next(lenp + 1);
			getNext(next, P);

			for (int i = 0; i < lenp; i++)
				printf ("next[%d]=%d\n", i, next[i]);
			puts ("");

			for (int i = 0, j = 0; T[i]; )
			{
				printf ("P[%d]=%c T[%d]=%c\n", j, P[j], i, T[i]);
				while (j > -1 && P[j] != T[i])
					j = next[j];
				++i;
				++j;

				printf (" i=%d j=%d\n", i, j);
				if (j >= lenp)
				{
					printf ("  ok i=%d j=%d (%s)\n", i, j, T + i - j);	
					return T + i - j;
				}
			}

			return NULL;
		}

		void getNext(vector<int> &next, char *P)
		{
			int j = -1;
			next[0] = -1;
			for (int i = 0; P[i]; )
			{
				while (j > -1 && P[j] != P[i])
					j = next[j];
				++i;
				++j;
				next[i] = (P[j] == P[i]) ? next[j] : j;
			}
		}
};

int main()
{
	Solution1 s;

//	cout << s.strStr("", "a") << endl;
//	cout << s.strStr("abcdabcdabab", "abab") << endl;
	cout << s.strStr("abababababacd", "ababababac") << endl;
//	cout << s.strStr("abababababacd", "abababac") << endl;

	return 0;
}

