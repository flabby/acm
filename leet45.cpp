/*
   Jump Game II
   遍历一遍
    记录当前这一步cur的范围里能到达的最大位置mx 更新cur，mx，stp
   */
#include "header.h"

class Solution
{
	public:
		int jump(int A[], int n)
		{
			if (n == 0)
				return -1;

			int stp(0);
			int mx(A[0]);
			int cur(0);

			for (int i = 1; i < n; i++)
			{
				if (i > cur)
				{
					if (mx < i) return -1;
					cur = mx;
					stp++;
				}
				mx = max(mx, i + A[i]);
			}

			return stp;
		}
};

int main()
{
	int a[] = {2, 3, 1, 1, 4};
	Solution s;
	cout << s.jump(a, 5) << endl;

	return 0;
}
