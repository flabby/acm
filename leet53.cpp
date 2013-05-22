/*
   Maximum Subarray
   */
#include "header.h"

class Solution
{
	public:
		int maxSubArray(int A[], int n)
		{
			int ret = A[0];
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				sum += A[i];
				ret = max(ret, sum);
				if (sum < 0)
					sum = 0;
			}

			return ret;
		}
};

int main()
{
	Solution s;
	int a[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int b[] = { -1, -2, -3, -4}; 
	cout << s.maxSubArray(a, 9) << endl;
	cout << s.maxSubArray(b, 4) << endl;

	return 0;
}
