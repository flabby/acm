/*
   Sort Colors
   */
#include "header.h"

class Solution
{
	public:
		void sortColors(int A[], int n)
		{
			if (!n) return;

			int d1 = -1;
			int d2 = -1;

			for (int i = 0; i < n; i++)
			{
		//		printf ("A[i=%d]=%d\n", i, A[i]);
				if (A[i] == 0)
				{
					int k = A[++d1];
					d2 = max(d2, d1);
					A[d1] = 0;
					A[i] = k;
		//			printf ("d1=%d d2=%d\n", d1, d2);
		//			pr(A, n);
				}
				if (A[i] == 1)
				{
					int k = A[++d2];
					A[d2] = 1;
					A[i] = k;

		//			printf ("d1=%d d2=%d\n", d1, d2);
		//			pr(A, n);
				}
	//			pr(A, n);
		//		puts ("");
			}
				pr(A, n);
		}
		void pr(int A[], int n)
		{
			for (int i = 0; i < n; i++)
				printf ("%d ", A[i]);
			puts ("");
		}

};

int main()
{
	int a[] = {2, 1, 1, 2, 0, 0};
	Solution s;

	s.sortColors(a, 6);

	return 0;
}
