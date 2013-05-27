#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <limits.h>

#include <map>
using namespace std;

typedef long long int lint;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

//        a[1]
//    a[2]    a[3]
// a[4] a[5] a[6]  a[7]
TreeNode *makeTree(int a[], int n, int id)
{
	TreeNode *root = NULL;
	if (a[id] != -1)
	{
//		printf ("n=%d id=%d\n", n, id);
		root = new TreeNode(a[id]);
		if (2 * id  <= n)
			root->left = makeTree(a, n, 2 * id);
		if (2 * id + 1 <= n)
			root->right = makeTree(a, n, 2 * id + 1);
	}
	return root;
}

//pre order
void prTree(TreeNode *root)
{
	if (root != NULL)
	{
		printf (" x=%d ------", root->val);
		if (root->left != NULL)
		{
			printf ("   [left] ");
			prTree(root->left);
			puts ("");
		}
		if (root->right != NULL)
		{
			printf ("   [right] ");
			prTree(root->right);
			puts ("");
		}
	}
}

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	void pr()
	{
		printf ("(%d -> %d)\n", start, end);
	}
};

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

void prMat(vector<vector<int> > &a)
{
	puts ("-----------------------");
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a[i].size(); j++)
			printf ("%d ", a[i][j]);
		puts ("");
	}
	puts ("-----------------------------\n");
}

ListNode *makeList(int a[], int n)
{
	ListNode *ret = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		ListNode *tmp = new ListNode(a[i]);
		tmp->next = ret;
		ret = tmp;
	}

	return ret;
}

void prList(ListNode *p)
{
	for (; p != NULL; p = p->next)
		printf ("%d -> ", p->val);
	puts (")");
}

#endif
