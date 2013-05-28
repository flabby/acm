/*
   Path Sum
   */
#include "header.h"

class Solution
{
	public:
		bool hasPathSum(TreeNode *root, int sum)
		{
			if (root == NULL)
				return false;

			if (root->left == NULL && root->right == NULL)
				return sum == root->val;

			if (root->left != NULL && hasPathSum(root->left, sum-root->val))
				return true;
			if (root->right != NULL && hasPathSum(root->right, sum-root->val))
				return true;
			return false;
		}
};

int main()
{
	int a[] = {-1, 1, 2, 3, 4, 5, 6};
	TreeNode *p = makeTree(a, 5, 1);
	prTree(p);

	Solution s;
	cout << s.hasPathSum(p, 8) << endl;

	return 0;
}
