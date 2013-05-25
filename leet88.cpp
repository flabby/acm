/*
   Merge Sorted Array
   */
#include "header.h"

class Solution
{
	public:
		void merge(int A[], int m, int B[], int n)
		{
			if (!n) return;

			int id = m + n - 1;

			int i = m - 1;
			int j = n - 1;
			int x, y;
			int mn = min(A[0], B[0]);
			while (i >= 0 || j >= 0)
			{
				if (i < 0)
					A[id--] = B[j--];
				else if (j < 0)
					break;
				else
				{
					if (A[i] > B[j])
						A[id--] = A[i--];
					else
						A[id--] = B[j--];
				}
			}

		}
};

int main()
{
	int a[100] = {1, 1, 2, 3, 6, 9, 10}; // 7
	int b[] = {0, 1, 4, 5, 7, 8, 11}; // 7

	Solution s;
	s.merge(a, 7, b, 7);

	for (int i = 0; i < 14; i++)
		printf ("%d ", a[i]);

	return 0;
}



				
