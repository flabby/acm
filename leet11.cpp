/*
   Container With Most Water
   */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	public:
		int maxArea(vector<int> &height)
		{
			int l = 0;
			int r = height.size() - 1;
			int ret = 0;
			while (l < r)
			{
				ret = max(ret, min(height[l], height[r]) * (r - l));
				if (height[l] < height[r])
					l++;
				else 
					r--;
			}

			return ret;
		}
};

int main()
{
	Solution s;
	vector<int>a; 
	a.push_back(2);
	a.push_back(5);
	a.push_back(5);
	a.push_back(5);
	a.push_back(1);
	a.push_back(1);

	cout << s.maxArea(a) << endl;

	return 0;
}

