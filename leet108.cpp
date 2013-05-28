/*
   Convert Sorted Array to Binary Search Tree
   */
#include "header.h"

class Solution
{
	public:
		TreeNode *sortedArrayToBST(vector<int> &num)
		{
			TreeNode *root(NULL);

			return dfs(num, 0, num.size() - 1);
		}

		TreeNode *dfs(vector<int> &num, int l, int r)
		{
			if (l > r)
				return NULL;

			int mid = (l + r) >> 1;
			TreeNode *p = new TreeNode(num[mid]);
			p->left = dfs(num, l, mid - 1);
			p->right = dfs(num, mid + 1, r);
			
			return p;
		}
};

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	vector<int>vc;
	for (int i = 0; i < 7; i++)
		vc.push_back(a[i]);

	Solution s;
	TreeNode *root = s.sortedArrayToBST(vc);
	prTree(root);

	return 0;
}

