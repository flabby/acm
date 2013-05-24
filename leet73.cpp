/*
	Set Matrix Zeroes
	*/
#include "header.h"

class Solution
{
	public:
		void setZeroes(vector<vector<int> > &mat)
		{
			int n = mat.size();
			if (!n) return;

			int m = mat[0].size();
			if (!m) return;

			bool firstCol = false;

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (!mat[i][j])
					{
						mat[i][0] = 0;
						if (j) mat[0][j] = 0;
						else	firstCol = true;
					}

			for (int i = 1; i < n; i++)
				if (!mat[i][0])
					for (int j = 0; j < m; j++)
						mat[i][j] = 0;

			for (int j = 1; j < m; j++)
				if (!mat[0][j])
					for (int i = 0; i < n; i++)
						mat[i][j] = 0;

			if (!mat[0][0])
				for (int j = 0; j < m; j++)
					mat[0][j] = 0;

			if (firstCol)
				for (int i = 0; i < n; i++)
					mat[i][0] = 0;
		}
};

void pr(vector<vector<int> > &a)
{
	puts ("");
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			printf ("%d ", a[i][j]);
		puts ("");
	}
}

int main()
{
	vector<vector<int> >a;
	for (int i = 0; i < 4; i++)
	{
		vector<int> k;
		for (int j = 0; j < 5; j++)
			k.push_back(i * 5 + j);
		a.push_back(k);
	}

	pr(a);
	Solution s;
	s.setZeroes(a);
	pr(a);
	return 0;
}
