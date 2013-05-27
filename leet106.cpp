/*
  	Construct Binary Tree from Inorder and Postorder Traversal 
   */
#include "header.h"

class Solution
{
	map<int, int>mp;

	public:
		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
		{
			int n = postorder.size();
			if (n == 0)
				return NULL;

			mp.clear();
			for (int i = 0; i < n; i++)
				mp[inorder[i]] = i;

//			for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++)
//				printf ("first=%d second=%d\n", it->first, it->second);

			return dfs(inorder, n-1, postorder, n-1, n);
		}

		TreeNode *dfs(vector<int> &in, int inEd, vector<int> &post, int poEd, int len)
		{
//			printf ("pst=%d ist=%d len=%d\n", pst, ist, len);
			if (!len)
				return NULL;

			TreeNode *p = new TreeNode(post[poEd]);
			int k = mp[post[poEd]];
//			printf (" k=%d k-ist=%d\n", k, k-ist);
//			char ch;
//			scanf ("%c", &ch);

			p->right = dfs(in, inEd, post, poEd-1, inEd - k);
			p->left = dfs(in, k-1, post, poEd-(inEd-k)-1, len-(inEd-k)-1);
			return p;
		}
};

int main()
{
	vector<int> post;
	post.push_back(4);
	post.push_back(5);
	post.push_back(2);
	post.push_back(6);
	post.push_back(7);
	post.push_back(3);
	post.push_back(1);

	vector<int> in;
	in.push_back(4);
	in.push_back(2);
	in.push_back(5);
	in.push_back(1);
	in.push_back(6);
	in.push_back(3);
	in.push_back(7);

	Solution s;
	TreeNode *ret = s.buildTree(in, post);
	prTree(ret);

	return 0;
}
