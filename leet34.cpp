/*
   Search for a Range
 */
#include "header.h"

class Solution
{
	public:
		vector<int> searchRange(int A[], int n, int target)
		{
			vector<int>ret;

			int l = binSearch(A, n, target);
			int r = binSearch(A, n, target + 1);

			//printf ("l=%d r=%d\n", l, r);
			if (l >= r)
				l = -1, r = 0;
			ret.push_back(l);
			ret.push_back(r - 1);
			//printf ("  l=%d r - 1=%d\n", l, r - 1);

			return ret;
		}

		int binSearch(int A[], int n, int target)
		{
			int l = 0;
			int r = n - 1;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (A[mid] < target)
					l = mid + 1;
				else if (A[mid] >= target)
					r = mid - 1;
			}

			return l;
		}
};

int main()
{
	int a[] = {5, 7, 7, 8, 8, 10};
	Solution s;

	s.searchRange(a, 6, 8);
	s.searchRange(a, 6, 7);
	s.searchRange(a, 6, 1);

	return 0;
}
