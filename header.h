#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>

#include <map>
using namespace std;

typedef long long int lint;

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
