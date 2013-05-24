/*
   Word Search
   */
#include "header.h"

int dir[][2] = {-1,0, 0,1, 1,0, 0,-1};

const int MAXM = 1100;

class Solution
{
	bool flg[MAXM][MAXM];
	public:
		bool exist(vector<vector<char> > &board, string word)
		{
			int len = word.length();
			if (!len) return true;

			int n = board.size();
			if (!n) return false;
			int m = board[0].size();
			if (!m) return false;

			memset(flg, 0, sizeof(flg));

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (board[i][j] == word[0])
					{
						flg[i][j] = true;
				//		printf ("i=%d j=%d\n", i, j);
						if (dfs(board, word, n, m, i, j, 1, len))
							return true;
						flg[i][j] = false;
					}
			return false;
		}
		
		bool in(int x, int y, int n, int m)
		{
			return x >= 0 && x < n && y >= 0 && y < m;
		}

		bool dfs(vector<vector<char> >&g, string &word, int n, int m, int x, int y, int dep, int len)
		{
			if (dep == len)
				return true;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dir[i][0];
				int ny = y + dir[i][1];
				if (in(nx, ny, n, m) && !flg[nx][ny] && g[nx][ny] == word[dep])
				{
					flg[nx][ny] = true;
					if (dfs(g, word, n, m, nx, ny, dep + 1, len))
						return true;
					flg[nx][ny] = false;
				}
			}
			return false;
		}
};

int main()
{
	vector<vector<char> >a;
	
	vector<char>ch;
	ch.push_back('A');
	ch.push_back('B');
	ch.push_back('C');
	ch.push_back('D');
	a.push_back(ch);
	ch.clear();

	ch.push_back('S');
	ch.push_back('F');
	ch.push_back('C');
	ch.push_back('S');
	a.push_back(ch);
	ch.clear();

	ch.push_back('A');
	ch.push_back('D');
	ch.push_back('E');
	ch.push_back('E');
	a.push_back(ch);
	Solution s;
	cout << s.exist(a, "ABCCED") << endl;

	return 0;
}

