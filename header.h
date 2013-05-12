#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

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
