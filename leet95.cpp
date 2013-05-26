/*
   Unique Binary Search Trees
   */
#include "header.h"

class Solution
{
	public:
		vector<TreeNode *> generateTrees(int n)
		{
			return dfs(1, n);
		}

		vector<TreeNode *> dfs(int st, int ed)
		{
			vector<TreeNode *>ret;
			if (st > ed)
			{
				ret.push_back(NULL);
				return ret;
			}

			for (int i = st; i <= ed; i++)
			{
				vector<TreeNode *> lsub = dfs(st, i - 1);
				vector<TreeNode *> rsub = dfs(i + 1, ed);

				for (int x = 0; x < lsub.size(); x++)
					for (int y = 0; y < rsub.size(); y++)
					{
						TreeNode *root = new TreeNode(i);
						root->left = lsub[x];
						root->right = rsub[y];

						ret.push_back(root);
					}
			}

			return ret;
		}
};

int main()
{
	Solution s;
	vector<TreeNode *> ret = s.generateTrees(3);

	//printf ("size=%d\n", ret.size());
	for (int i = 0; i < ret.size(); i++)
	{
		prTree(ret[i]);
		puts ("\n");
	}

	return 0;
}
