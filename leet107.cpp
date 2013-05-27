/*
   Binary Tree Level Order Traversal
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
		vector<vector<int> > levelOrderBottom(TreeNode *root)
		{
			vector<vector<int> >ret;
			vector<vector<int> >ret1;
			vector<int>l;
			if (root == NULL)
				return ret;

			queue<node> qu;
			qu.push(node(root, 0));
			
			int pre = 0;
			while (!qu.empty())
			{
				node *d = &qu.front();
				if (d->lv != pre)
				{
			//		printf ("lv=%d val=%d\n", d->lv, (d->p)->val);
					ret.push_back(l);
					l.clear();
				}

				TreeNode *tmp = d->p;
				pre = d->lv;
				l.push_back(tmp->val);
			//	printf ("tmp->val=%d d->lv=%d\n", tmp->val, d->lv);
				if (tmp->left != NULL)
					qu.push(node(tmp->left, d->lv+1));
				if (tmp->right != NULL)
					qu.push(node(tmp->right, d->lv+1));

				qu.pop();
			}
			ret.push_back(l);
			for (int i = 0; i < ret.size(); i++)
				ret1.push_back(ret[ret.size() - i -1]);

			return ret1;
		}
};

int main()
{
	int a[] = {-1, 1, 2, 2, -1, 3, 3, -1};
	int b[] = {-1, 1, -1, 2, -1, -1, 2};
	TreeNode *t1 = makeTree(a, 7, 1);
	TreeNode *t2 = makeTree(b, 6, 1);

	Solution s;
	vector<vector<int> > ret = s.levelOrderBottom(t1);

	for (int i = 0; i < ret.size(); i++)
	{
		printf ("i=%d\n", i);
		for (int j = 0; j < ret[i].size(); j++)
			printf ("%d ", ret[i][j]);
		puts ("");
	}
	return 0;
}
