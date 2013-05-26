/*
   Binary Tree Inorder Traversal
   */
#include "header.h"

class Solution
{
	public:
		vector<int> inorderTraversal(TreeNode *root)
		{
			vector<int> ret;

			inOrder(ret, root);
			return ret;
		}

		void inOrder(vector<int> &ret, TreeNode *root)
		{
			if (root != NULL)
			{
				if (root->left != NULL)
					inOrder(ret, root->left);
				ret.push_back(root->val);
				if (root->right != NULL)
					inOrder(ret, root->right);
			}
		}
};

int main()
{
	int a[] = {-1, 1, -1, 2, -1, -1, 3};

	TreeNode *tree = makeTree(a, 6, 1);
	prTree(tree);
	
	Solution s;
	vector<int> ret = s.inorderTraversal(tree);
	for (int i = 0; i < ret.size(); i++)
		printf ("%d ", ret[i]);
	puts ("");

	return 0;
}
