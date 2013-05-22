/*
   N-Queens II
   输出最后的方案数
   位运算 matrix67
   */
#include "header.h"

class Solution
{
	public:
		int cnt;
		int upperlimit;
		int totalNQueens(int n)
		{
			cnt = 0;
			upperlimit = (1 << n) - 1;
			test(0, 0, 0);
			return cnt;
		}
		
		void test(int row, int ld, int rd)
		{
			if (row != upperlimit)
			{
				int pos = upperlimit & ~(row | ld | rd);
				while (pos)
				{
					int p = pos & -pos;
					
					test(row + p, (ld + p) << 1, (rd + p) >> 1);
					pos -= p;
				}
			}
			else
				cnt++;
		}
};

int main()
{
	Solution s;
	cout << s.totalNQueens(8) << endl;
	cout << s.totalNQueens(4) << endl;

	return 0;
}
