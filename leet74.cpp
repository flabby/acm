/*
   Search a 2D Matrix
   */

#include "header.h"

class Solution
{
	public:
		bool searchMatrix(vector<vector<int> > &mat, int target)
		{
			int n = mat.size();
			if (!n) return false;
			int m = mat[0].size();
			if (!m) return false;

			vector<int> l;
			for (int i = 0; i < n; i++)
				l.push_back(mat[i][m - 1]);

			int id = bSearch(l, target);
			if (id >= n)
				return false;

			int ret = bSearch(mat[id], target);
			if (ret >= m)
				return false;

			//printf ("[id=%d][ret=%d] = %d\n", id, ret, mat[id][ret]);
			return mat[id][ret] == target;
		}

		int bSearch(vector<int> &a, int target)
		{
			int l = 0;
			int r = a.size() - 1;

			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (target > a[mid])
					l = mid + 1;
				else
					r = mid - 1;
			}

			return l;
		}
};

int main()
{
	vector<vector<int> >a;

	vector<int>k;
	k.push_back(1);
	k.push_back(3);
	k.push_back(5);
	k.push_back(7);
	a.push_back(k);
	k.clear();

	k.push_back(10);
	k.push_back(11);
	k.push_back(16);
	k.push_back(20);
	a.push_back(k);
	k.clear();

	k.push_back(23);
	k.push_back(30);
	k.push_back(34);
	k.push_back(50);
	a.push_back(k);
	k.clear();

	Solution s;
	cout << s.searchMatrix(a, 3) << endl;

	return 0;
}
