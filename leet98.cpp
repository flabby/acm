/*
   Validate Binary Search Tree
   */
#include "header.h"

class Solution
{
	public:
		bool isValidBST(TreeNode *root)
		{
			if (root == NULL)
				return true;

			return dfs(root, INT_MIN, INT_MAX);
		}

		bool dfs(TreeNode *root, int mn, int mx)
		{	
			if (root == NULL)
				return true;

			if (root->val > mn && root->val < mx)
				return dfs(root->left, mn, root->val)
					&& dfs(root->right, root->val, mx);
			return false;
		}
};

int main()
{
	int a[] = {-1, 1, 2, 3, -1, -1, 4};
	TreeNode *root = makeTree(a, 2, 1);
	prTree(root);

	Solution s;
	cout << s.isValidBST(root) << endl;

	return 0;
}
