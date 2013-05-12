/*
   Remove Duplicates from sorted array
   */
#include "header.h"

class Solution
{
	public:
		int removeDuplicates(int A[], int n)
		{
			int len = 0;
			if (n < 2)
				return n;

			for (int j = 1; j < n; j++)
				if (A[len] != A[j])
					A[++len] = A[j];

			return len + 1;
		}
};

int main()
{
	int a[] = {1, 2, 2, 3, 3, 4};
	Solution s;
	cout << s.removeDuplicates(a, 6) << endl;

	return 0;
}
