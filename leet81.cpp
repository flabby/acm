/*
   Search in Rotated Sorted Array II
   */

#include "header.h"

class Solution
{
	public:
		bool search(int A[], int n, int target)
		{
			int l = 0;
			int r = n - 1;
			
			while (l <= r)
			{
				int mid = (l + r) >> 1;

			//	printf ("[l=%d]=%d [mid=%d]=%d [r=%d]=%d\n", l, A[l], mid, A[mid], r, A[r]);
				if (A[mid] == target)
					return true;
				
				if (A[l] < A[mid])
				{
					if (A[l] <= target && target < A[mid])
						r = mid - 1;
					else
						l = mid + 1;
				}
				else if (A[l] > A[mid])
				{
					if (A[mid] < target && target <= A[r])
						l = mid + 1;
					else 
						r = mid - 1;
				}
				else 
					l++;
			}
			return false;
		}
};

int main()
{
	int a[] = {4, 5, 6, 7, 0, 1, 2, 3};
	int b[] = {1, 3, 1, 1, 1};
	Solution s;

//	cout << s.search(a, 8, 6) << endl;
//	cout << s.search(a, 8, 0) << endl;
//	cout << s.search(a, 8, 2) << endl;
	cout << s.search(b, 5, 3) << endl;

	return 0;
}
