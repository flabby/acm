/*
   Same Tree
   */
#include "header.h"

class Solution 
{
	public:
		bool isSameTree(TreeNode *p, TreeNode *q)
		{
			if (p == NULL)
				return q == NULL;

			if (q == NULL || p->val != q->val)
				return false;

			if (p->left != NULL && !isSameTree(p->left, q->left))
				return false;

			if (p->right != NULL && !isSameTree(p->right, q->right))
				return false;

			return true;
		}
};

int main()
{
	int a[] = {-1, 1, -1, 2, -1, -1, 3};
	int b[] = {-1, 1, -1, 2, -1, -1, 2};
	TreeNode *t1 = makeTree(a, 6, 1);
	TreeNode *t2 = makeTree(b, 6, 1);

	Solution s;
	cout << s.isSameTree(t1, t2) << endl;

	return 0;
}
