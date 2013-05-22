/*
   N-Queens
   dfs
   */
#include "header.h"

class Solution
{
	vector<vector<string> > ret;
	public:
		vector<vector<string> > solveNQueens(int n)
		{
			ret.clear();
			int* flg = new int[n + 1];
			int* pos = new int[n + 1];
			for (int i = 0; i < n; i++)
				flg[i] = 0;

			dfs(0, n, flg, pos);
			pr();
			return ret;
		}
		
		void pr()
		{
			for (int i = 0; i < ret.size(); i++)
			{
				for (int x = 0; x < ret[i].size(); x++)
					cout << ret[i][x] << endl;
				cout << endl;
			}
		}

		void dfs(int dep, int n, int flg[], int pos[])
		{
			if (dep == n)
			{
				vector<string> g;
				for (int i = 0; i < n; i++)
				{
					string row(n, '.');
					row[pos[i]] = 'Q';
					g.push_back(row);
				}
				ret.push_back(g);
				return;
			}
			
			for (int i = 0; i < n; i++)
				if (!flg[i] && isOk(dep, i, pos)) 
				{
					flg[i] = 1;
					pos[dep] = i;
					dfs(dep + 1, n, flg, pos);
					flg[i] = 0;
				}
		}
		
		bool isOk(int dep, int y, int pos[])
		{
			for (int i = 0; i < dep; i++)
				if (abs(i - dep) == abs(pos[i] - y))
					return false;
			return true;
		}
};

int main()
{	
	Solution s;
	s.solveNQueens(4);

	return 0;
}
