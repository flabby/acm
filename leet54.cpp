/*
   Spiral Matrix
   */
#include "header.h"

int dir[][2] = {0,1, 1,0, 0,-1, -1,0};

class Solution
{
	public:
		vector<int> spiralOrder(vector<vector<int> > &mat)
		{
			vector<int> ret;

			int row0 = 0;
			int row1 = mat.size();
			if (row1 == 0) return ret;

			int col0 = 0;
			int col1 = mat[0].size();
			if (col1 == 0) return ret;

			int d = 0;
			int x = 0;
			int y = -1;

			while (row0 < row1 && col0 < col1)
			{
				int nx = x + dir[d][0];
				int ny = y + dir[d][1];

				if (!(nx >= row0 && nx < row1 && ny >= col0 && ny < col1))
				{
					if (d == 0) row0++;
					if (d == 1) col1--;
					if (d == 2) row1--;
					if (d == 3) col0++;

					d = (d + 1) % 4;
					nx = x + dir[d][0];
					ny = y + dir[d][1];
				}
				
				//printf ("x=%d y=%d nx=%d ny=%d\n", x, y, nx, ny);
				if (!(nx >= row0 && nx < row1 && ny >= col0 && ny < col1))
					break;

				x = nx;
				y = ny;
				ret.push_back(mat[x][y]);
			}

			return ret;
		}
};

int main()
{
	vector<vector<int> >a;
	for (int i = 0; i < 3; i++)
	{
		vector<int> k;
		for (int j = 0; j < 3; j++)
			k.push_back(i * 3 + j + 1);
		a.push_back(k);
	}

	vector<int> ret;
	Solution s;
	ret = s.spiralOrder(a);

	for (int i = 0; i < ret.size(); i++)
		printf ("%d ", ret[i]);
	return 0;
}
					
