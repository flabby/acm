/*
   Search Insert Position
   */
#include "header.h"

class Solution 
{
	public:
		int searchInsert(int A[], int n, int target)
		{
			int l = 0;
			int r = n - 1;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				//printf ("A[l=%d]=%d A[r=%d]=%d A[mid=%d]=%d\n", l, A[l], r, A[r], mid, A[mid]);

				if (target <=  A[mid])
					r = mid - 1;
				else 
					l = mid + 1;
			}

			return l;
		}
};

int main()
{
	int a[] = {1, 3, 5, 6};

	Solution s;
	cout << s.searchInsert(a, 4, 5) << endl;
	cout << s.searchInsert(a, 4, 1) << endl;
	cout << s.searchInsert(a, 4, 2) << endl;
	cout << s.searchInsert(a, 4, 7) << endl;

	return 0;
}
