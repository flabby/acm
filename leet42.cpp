/*
   Trapping Rain Water
   */
#include "header.h"

class Solution
{
	public:
		int trap(int A[], int n)
		{
			if (n <= 2)
				return 0;

			int *left = new int[n + 1];
			int *right = new int[n + 1];

			left[0] = 0;
			for (int i = 1; i < n; i++)
				left[i] = max(A[i - 1], left[i - 1]);

			right[n - 1] = 0;
			for (int i = n - 2; i >= 0; i--)
				right[i] = max(right[i + 1], A[i + 1]);

			int ret = 0;
			for (int i = 0; i < n; i++)
			{
				int k = min(left[i], right[i]);
				if (k > A[i])
					ret += k - A[i];

			}

			delete[] left;
			delete[] right;
			return ret;
		}
};

int main()
{
	int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int b[] = {2, 1, 0, 2};
	Solution s;
	cout << s.trap(a, 12) << endl;
	cout << s.trap(b, 4) << endl;

	return 0;
}
