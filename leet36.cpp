/*
   Valid Sodoku
 */
#include "header.h"

class Solution
{
	public:
		bool isValidSudoku(vector<vector<char> > &board)
		{
			char nine[10];
			nine[9] = '\0';

			for (int i = 0; i < 9; i++)
			{
				getCol(nine, i, board);
				//printf ("col[%d]=(%s)\n", i, nine);
				if (!isOk(nine))
					return 0;
				getRow(nine, i, board);
				//printf ("row[%d]=(%s)\n", i, nine);
				if (!isOk(nine))
					return 0;
			}

			for (int i = 0; i < 9; i += 3)
				for (int j = 0; j < 9; j += 3)
				{
					getSub(nine, i, j, board);
				//	printf ("Sub(%d %d)=(%s)\n", i, j, nine);	
					if (!isOk(nine))
						return 0;
				}

			return 1;
		}

		void getRow(char *p, int id, vector<vector<char> >&board)
		{
			for (int i = 0; i < 9; i++)
				p[i] = board[id][i];
		}
		void getCol(char *p, int id, vector<vector<char> >&board)
		{
			for (int i = 0; i < 9; i++)
				p[i] = board[i][id];
		}
		void getSub(char *p, int x, int y, vector<vector<char> >&board)	
		{
			int k = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					p[k++] = board[x+i][y+j];
		}
		bool isOk(char *p)
		{
			int flg[10];
			for (int i = 0; i < 9; i++)
				flg[i] = 0;
			for (int i = 0; i < 9; i++)
				if (p[i] != '.' && flg[p[i] - '1'] > 0)
					return false;
				else if (p[i] != '.')
					flg[p[i] - '1'] = 1;
			return true;
		}
};

string s[] = {
	"..5......",
	"4........",
	".......3.",
	".5....7..",
	"2...9....",
	".....8...",
	"....6...5",
	"...74....",
	".8......."
};
string s1[] = {
	"...94....",
	"27....9..",
	"44.......",
	"..6.....9",
	"........4",
	"..7..2.5.",
	".......2.",
	".........",
	"...8.96.."};
int main()
{
	vector<vector<char> > a;
	for (int i = 0; i < 9; i++)
	{
		vector<char> tmp;
		for (int j = 0; j < 9; j++)
			tmp.push_back(s[i][j]);
		a.push_back(tmp);
	}

	Solution s;
	cout << s.isValidSudoku(a) << endl;
	return 0;
}
