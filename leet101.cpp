/*
   Symmetric Tree
   */
#include "header.h"

class Solution
{
	public:
		bool isSymmetric(TreeNode *root)
		{
			if (root == NULL)
				return true;

			//return dfs(root, root);
			return bfs(root);
		}

		bool bfs(TreeNode *root)
		{
			queue<TreeNode *>lq, rq;
			lq.push(root);
			rq.push(root);
			TreeNode *p, *q;
			while (!lq.empty() && !rq.empty())
			{
				p = lq.front(); lq.pop();
				q = rq.front(); rq.pop();

				if (p == NULL && q == NULL)
					continue;
				else if (p == NULL || q == NULL || p->val != q->val)
					return false;

				lq.push(p->left); lq.push(p->right);
				rq.push(q->right); rq.push(q->left);
			}

			return lq.empty() && rq.empty();
		}

		bool dfs(TreeNode *p, TreeNode *q)
		{
			if (p == NULL)
				return q == NULL;

			if (q == NULL || p->val != q->val)
				return false;

			if (p->left != NULL && !dfs(p->left, q->right))
				return false;

			if (p->right != NULL && !dfs(p->right, q->left))
				return false;
			return true;
		}
};

int main()
{
	int a[] = {-1, 1, 2, 2, -1, 3, 3, -1};
	int b[] = {-1, 1, -1, 2, -1, -1, 2};
	TreeNode *t1 = makeTree(a, 7, 1);
	TreeNode *t2 = makeTree(b, 6, 1);

	Solution s;
	cout << s.isSymmetric(t1) << endl;

	return 0;
}
