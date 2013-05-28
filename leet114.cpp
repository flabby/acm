/*
   Flatten Binary Tree to Linked List
   */
#include "header.h"

class Solution
{
	public:
		void flatten(TreeNode *root)
		{
			flat(root);
		}

		TreeNode *flat(TreeNode *root)
		{
			if (root == NULL)
				return root;

			TreeNode *llast = flat(root->left);
			TreeNode *rlast = flat(root->right);

			if (llast != NULL)
				llast->right = root->right;

			if (root->left != NULL)
			{
				root->right = root->left;
				root->left = NULL;
			}

			if (rlast) return rlast;
			if (llast) return llast;
			return root;
		}
};

int main()
{
	int a[] = {-1, 1, 2, 2, 4, 5, 6};
	TreeNode *p = makeTree(a, 3, 1);
	prTree(p);

	Solution s;
	s.flatten(p);
	prTree(p);

	return 0;
}
