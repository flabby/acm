/*
 	Minimum Depth of Binary Tree 
   */
#include "header.h"

class Solution
{
	public:
		int minDepth(TreeNode *root)
		{
			if (root == NULL)
				return 0;
			
			if (root->left == NULL && root->right == NULL)
				return 1;
			
			int ret = INT_MAX;
			if (root->left != NULL)
				ret = min(ret, minDepth(root->left));
			if (root->right != NULL)
				ret = min(ret, minDepth(root->right));
			return ret + 1;
		}
};

int main()
{
	int a[] = {-1, 1, 2, 3, 4, 5, 6};
	TreeNode *p = makeTree(a, 5, 1);

	Solution s;
	cout << s.minDepth(p) << endl;

	return 0;
}
