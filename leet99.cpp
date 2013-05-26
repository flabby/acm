/*
   Recovery Binary Search Tree
   */
#include "header.h"

class Solution
{
	public:
		void recoverTree(TreeNode *root)
		{
			TreeNode *p1(NULL);
			TreeNode *p2(NULL);
			TreeNode *pre(NULL);

			dfs(root, p1, p2, pre);

			if (p1 && p2)
				swap(p1->val, p2->val);
		}

		void dfs(TreeNode *root, TreeNode *&p1, TreeNode *&p2, TreeNode *&pre)
		{
			if (root == NULL)
				return;

			dfs(root->left, p1, p2, pre);
			if (pre != NULL && pre->val > root->val)
			{
				p2 = root;
				if (p1 == NULL)
					p1 = pre;
			}
			pre = root;
			dfs(root->right, p1, p2, pre);
		}
};

int main()
{
	int a[] = {-1, 1, -1, 2, -1, -1, 3};
	TreeNode *tree = makeTree(a, 6, 1);
	prTree(tree);

	Solution s;
	s.recoverTree(tree);
	prTree(tree);

	return 0;
}
