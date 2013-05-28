/*
   Path Sum II
   */
#include "header.h"

class Solution
{
	public:
		vector<vector<int> > pathSum(TreeNode *root, int sum)
		{
			vector<vector<int> >ret;

			if (root == NULL)
				return ret;

			vector<int>path;
			dfs(ret, path, root, sum);

			return ret;
		}

		void dfs(vector<vector<int> >&ret, vector<int>&path, TreeNode *p, int sum)
		{
			path.push_back(p->val);
			if (p->left == NULL && p->right == NULL && p->val == sum)
			{
				ret.push_back(path);	
				path.pop_back();
				return;
			}

			if (p->left != NULL)
				dfs(ret, path, p->left, sum - p->val);

			if (p->right != NULL)
				dfs(ret, path, p->right, sum - p->val);
			path.pop_back();
		}
};

int main()
{
	int a[] = {-1, 1, 2, 2, 4, 5, 6};
	TreeNode *p = makeTree(a, 3, 1);
	prTree(p);

	Solution s;
	vector<vector<int> > ret = s.pathSum(p, 3);
	prMat(ret);

	return 0;
}
