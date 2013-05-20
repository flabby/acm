/*
   Next Permutation
   */
#include "header.h"

class Solution
{	
	public:
		void nextPermutation(vector<int> &num)
		{
		//	next_permutation(num.begin(), num.end());
			int len = num.size();
			

			
			if (len == 1)
				return ;

			int x1 = len - 2;
			for (; x1 >= 0; x1--)
				if (num[x1] < num[x1 + 1])
					break;

			int x2 = len - 1;
			for (; x2 >= 0; x2--)
				if (num[x2] > num[x1])
					break;

	//		printf ("x1=%d x2=%d\n", x1, x2);
	//		printf ("num[-1]=%d\n", num[-1]);
			swap(num[x1], num[x2]);
			reverse(num.begin() + x1 + 1 , num.end());
			
			for (int i = 0; i < len; i++)
				printf ("%d ", num[i]);
			puts ("\n");
		}
};

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	vector<int> avc(a, a + 3); 

	Solution s;
	for (int i = 0; i < 10; i++)
		s.nextPermutation(avc);

	return 0;
}
