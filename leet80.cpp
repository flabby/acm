/*
   Remove Duplicates from Sorted Array II
   */
#include "header.h"

class Solution
{
	public:
		int removeDuplicates(int A[], int n)
		{
			map<int, int>mp;
			
			bool flg[n];
			memset(flg, 0, sizeof(flg));
			for (int i = 0; i < n; i++)
			{
				if (mp[A[i]] > 1)
					flg[i] = true;
				else
					mp[A[i]]++;
			}

			int j = 0;
			for (int i = 0; i < n; i++)
			{
				if (!flg[i])
					A[j++] = A[i];
			}

			return j;
		}

		//break the orders
		int removeDuplicates1(int A[], int n)
		{
			map<int, int>mp;
			int ret = n;

			int j = n;
			for (int i = n - 1; i >= 0; i--)
			{
				if (mp[A[i]] > 1)
				{
					int k = A[i];
					A[i] = A[--j];
					A[j] = k;
					ret--;
				}
				else
					mp[A[i]]++;
			}
			
//			for (int i = 0; i < n; i++)
//				printf ("%d ", A[i]);
//			puts ("");

			return ret;
		}
};

int main()
{
	int A[] = {1, 1, 1, 2, 2, 3};
	Solution s;		
	cout << s.removeDuplicates(A, 6) << endl;

	return 0;
}
