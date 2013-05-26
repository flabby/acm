/*
   Largest Rectangle in Histogram
   */
#include "header.h"

class Solution 
{
	public:
		int largestRectangleArea(vector<int> & height)
		{
			int ret = 0;
			int n = height.size();

			if (!n) return ret;

			int left[n];
			int right[n];
			for (int i = 0; i < n; i++)
				left[i] = right[i] = i;

			for (int i = 1; i < n; i++)
			{
				while (left[i] > 0 && height[left[i] - 1] >= height[i])
					left[i] = left[left[i] - 1];
			}

			for (int i = n - 2; i >= 0; i--)
			{
				while (right[i] < n - 1 && height[right[i] + 1] >= height[i])
					right[i] = right[right[i] + 1];
			}
//			pr(left, n);
//			pr(right, n);
			for (int i = 0; i < n; i++)
				ret = max(ret, height[i] * (right[i] - left[i] + 1));

			return ret;
		}
		void pr(int a[], int n)
		{
			for (int i = 0; i < n; i++)
				printf ("%2d ", a[i]);
			puts ("");
		}
};

int main()
{
	int a[] = {2, 1, 5, 6, 2, 3};
	vector<int> data;
	for (int i = 0; i < 6; i++)
		data.push_back(a[i]);

	Solution s;
	cout << s.largestRectangleArea(data) << endl;

	return 0;
}
