/*
 3Sum Closest
 */
#include <iostream>
#include <vector>
using namespace std;

#include <algorithm>

class Solution
{
	public:
		int threeSumClosest(vector<int> &num, int target) 
		{
			sort (num.begin(), num.end());
			
			int ret = num[0] + num[1] + num[2];
			for (int i = 0; i < num.size() - 2; i++)
			{
				int j = i + 1;
				int k = num.size() - 1;
				while (j < k)
				{
					int sum = num[i] + num[j] + num[k];
					if (abs(sum - target) < abs(ret - target))
						ret = sum;

					if (sum < target)
						j++;
					else
						k--;
				}
			}

			return ret;
		}
};

int main()
{
	Solution s;
	vector<int> a;
	a.push_back(-1);
	a.push_back(2);
	a.push_back(1);
	a.push_back(-4);

	cout << s.threeSumClosest(a, 1) << endl;

	return 0;
}

			
