/*
  Binary Tree Zigzag Level Order Traversal 
   */
#include "header.h"

struct node
{
	TreeNode *p;
	int lv;
	node (TreeNode *q = NULL, int k = -1): p(q), lv(k){}
};

class Solution
{
	public:
		vector<vector<int> > zigzagLevelOrder(TreeNode *root)
		{
			vector<vector<int> > ret;
			vector<int>l;
			if (root == NULL)
				return ret;

			queue<node>qu;
			qu.push(node(root, 0));
			int pre = 0;
			int order = 0;

			while (!qu.empty())
			{
				node *d = &qu.front();

				if (d->lv != pre)
				{
					if (order)
						reverse(l.begin(), l.end());
					ret.push_back(l);
					l.clear();
					order = 1 - order;
				}
				TreeNode *tmp = d->p;
				l.push_back(tmp->val);
				if (tmp->left != NULL)
					qu.push(node(tmp->left, d->lv + 1));
				if (tmp->right != NULL)
					qu.push(node(tmp->right, d->lv + 1));

				pre = d->lv;
				qu.pop();
			}
			if (order)
				reverse(l.begin(), l.end());
			ret.push_back(l);
			return ret;
		}
};

int main()
{
	int a[] = {-1, 1, 2, 3, -1, 4, 5, -1};
	int b[] = {-1, 1, -1, 2, -1, -1, 2};
	TreeNode *t1 = makeTree(a, 7, 1);
	TreeNode *t2 = makeTree(b, 6, 1);

	Solution s;
	vector<vector<int> > ret = s.zigzagLevelOrder(t1);

	for (int i = 0; i < ret.size(); i++)
	{
		printf ("i=%d\n", i);
		for (int j = 0; j < ret[i].size(); j++)
			printf ("%d ", ret[i][j]);
		puts ("");
	}
	return 0;
}
