/*
   Rotate Image
   in place
 */
#include "header.h"

class Solution
{
	public:
		void rotate(vector<vector<int> > &mat)
		{
			int n = mat.size();
			for (int st = 0, ed = n - 1; st < ed; st++, ed--)
			{
				for (int i = 0; i < ed - st; i++)
				{
					int tmp = mat[st][st + i];
					mat[st][st + i] = mat[ed - i][st];
					mat[ed - i][st] = mat[ed][ed - i];
					mat[ed][ed - i] = mat[st + i][ed];
					mat[st + i][ed] = tmp;
				}
			}
		}
};

void pr(vector<vector<int> > &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			printf ("%d ", a[i][j]);
		puts ("");
	}
	puts ("");
}

int main()
{
	Solution s;
	vector<vector<int> >a;

	int n = 4;
	for (int i = 0; i < n; i++)
	{
		vector<int>k;
		for (int j = 0; j < n; j++)
			k.push_back(j + 1);
		a.push_back(k);
	}
	pr(a);
	s.rotate(a);
	pr(a);

	return 0;
}
