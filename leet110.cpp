/*
   Balanced Binary Tree
   */
#include "header.h"

class Solution
{
	public:
		bool isBalanced(TreeNode *root)
		{
			return height(root) != -1;
		}
		int height(TreeNode *root)
		{
			if (root == NULL) 
				return 0;

			int lh = height(root->left);
			if (lh == -1)
				return -1;

			int rh = height(root->right);
			if (rh == -1)
				return -1;

			if (abs(lh - rh) > 1)
				return -1;

			return 1 + max(lh, rh);
		}
};

int main()
{
	int a[] = {-1, 1, 2, 3, 4, 5, 6};
	TreeNode *p = makeTree(a, 5, 1);

	Solution s;
	cout << s.isBalanced(p) << endl;

	return 0;
}
