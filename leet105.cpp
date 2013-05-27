/*
  	Construct Binary Tree from Preorder and Inorder Traversal 
   */
#include "header.h"

class Solution
{
	map<int, int>mp;

	public:
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
		{
			int n = preorder.size();
			if (n == 0)
				return NULL;

			mp.clear();
			for (int i = 0; i < n; i++)
				mp[inorder[i]] = i;

//			for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++)
//				printf ("first=%d second=%d\n", it->first, it->second);

			return dfs(preorder, 0, inorder, 0, n);
		}

		TreeNode *dfs(vector<int> &pre, int pst, vector<int> &in, int ist, int len)
		{
//			printf ("pst=%d ist=%d len=%d\n", pst, ist, len);
			if (!len)
				return NULL;

			TreeNode *p = new TreeNode(pre[pst]);
			int k = mp[pre[pst]];
//			printf (" k=%d k-ist=%d\n", k, k-ist);
//			char ch;
//			scanf ("%c", &ch);

			p->left = dfs(pre, pst+1, in, ist, k - ist);
			p->right = dfs(pre, pst+k-ist+1, in, k+1, len-(k-ist)-1);
			return p;
		}
};

int main()
{
	vector<int> pre;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(5);
	pre.push_back(3);
	pre.push_back(6);
	pre.push_back(7);

	vector<int> in;
	in.push_back(4);
	in.push_back(2);
	in.push_back(5);
	in.push_back(1);
	in.push_back(6);
	in.push_back(3);
	in.push_back(7);

	Solution s;
	TreeNode *ret = s.buildTree(pre, in);
	prTree(ret);

	return 0;
}
