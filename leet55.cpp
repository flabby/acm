/*
   Jump Game
   */
#include "header.h"

class Solution
{
	public:
		bool canJump(int A[], int n)
		{
			int mx = 0;
			for (int i = 0; i < n; i++)
			{
				if (i <= mx)
					mx = max(mx, i + A[i]);
			}
			
			return mx >= n - 1;
		}
};

int main()
{
	int a[] = {2, 3, 1, 1, 4};
	Solution s;
	cout << s.canJump(a, 5) << endl;

	return 0;
}
