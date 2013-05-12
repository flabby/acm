/*
   Remove Element
   */
#include "header.h"

class Solution
{
	public:
		int removeElement(int A[], int n, int elem)
		{
			int i = 0;
			
			for (int j = 0; j < n; j++)
				if (A[j] != elem)
				{
					swap(A[i], A[j]);
					i++;
				}


			//for (int k = 0; k < i; k++)
			//	printf ("A[%d]=%d\n", k, A[k]);

			return i;
		}
};

int main()
{
	int a[] = {3, 1, 2, 3, 4, 3, 3, 2, 1};

	Solution s;
	cout << s.removeElement(a, 9, 3) << endl;

	return 0;
}
