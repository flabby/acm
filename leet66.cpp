/*
   Plus One
   */
#include "header.h"

class Solution
{
	public:
		vector<int> plusOne(vector<int> &d)
		{
			vector<int>::iterator it;

			int carry = 1;
			for (int i = d.size() - 1; i >= 0; i--)
			{
				int k = d[i] + carry;
				d[i] = k % 10;
				carry = k / 10;
				if (carry == 0)
					break;
			}

			if (carry > 0)
				d.insert(d.begin(), carry);

			return d;
		}
};

int main()
{
	vector<int>a;
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);
	a.push_back(9);

	Solution s;
	vector<int> ret = s.plusOne(a);
	for (int i = 0; i < ret.size(); i++)
		printf ("%d ", ret[i]);
	return 0;
}

