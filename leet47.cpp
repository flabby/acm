/*
   Permutations
 */
#include "header.h"

bool nextPermutation(vector<int> &num)
{
	//	next_permutation(num.begin(), num.end());
	int len = num.size();

	if (len == 1)
		return false;

	int x1 = len - 2;
	for (; x1 >= 0; x1--)
		if (num[x1] < num[x1 + 1])
			break;

	if (x1 < 0)
		return false;

	int x2 = len - 1;
	for (; x2 >= 0; x2--)
		if (num[x2] > num[x1])
			break;

	//		printf ("x1=%d x2=%d\n", x1, x2);
	//		printf ("num[-1]=%d\n", num[-1]);
	swap(num[x1], num[x2]);
	reverse(num.begin() + x1 + 1 , num.end());

//	for (int i = 0; i < len; i++)
//		printf ("%d ", num[i]);
//	puts ("\n");
	return true;
}

class Solution
{
	public:
		vector<vector<int> > permuteUnique(vector<int> &num)
		{
			vector<vector<int> >ret;

			if (num.size() <= 0) return ret;

			sort(num.begin(), num.end());
			do
			{
				ret.push_back(num);
			}while (nextPermutation(num));

			return ret;
		}
};

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	Solution s;
	s.permuteUnique(a);

	return 0;
}

