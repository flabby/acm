/*
  Maximun Depth of Binary Tree 
   */
#include "header.h"

class Solution
{
	public:
		int maxDepth(TreeNode *root)
		{
			if (root == NULL)
				return 0;

			int ret = 0;
			if (root->left != NULL)
				ret = max(ret, maxDepth(root->left));
			if (root->right != NULL)
				ret = max(ret, maxDepth(root->right));

			return ret + 1;
		}
};

int main()
{
	int a[] = {-1, 1, 2, 3, -1, 4, 5, -1};
	int b[] = {-1, 1, -1, 2, -1, -1, 2};
	TreeNode *t1 = makeTree(a, 7, 1);
	TreeNode *t2 = makeTree(b, 6, 1);

	Solution s;
	cout << s.maxDepth(t1) << endl;

	return 0;
}
