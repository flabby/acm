/*
   Remove Nth Node From End of List
   */
#include <iostream>
#include <cstdio>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL) {}
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

void pr(ListNode *p)
{
	for (; p != NULL; p = p->next)
		printf ("%d -> ", p->val);
	printf ("\n");
}

class Solution
{
	public:
		ListNode *removeNthFromEnd(ListNode *head, int n)
		{
			ListNode *p = head;
			ListNode *q = head;
			for (int i = 0; i < n; i++)
				q = q->next;
			if (q == NULL)
			{
				head = p->next;
				delete p;
				return head;
			}
			
			for (; q->next != NULL;  q = q->next, p = p->next);

			ListNode *d = p->next;
			if (d != NULL)
			{
				p->next = d->next;
				delete d;
			}
			
			return head;
		}
};

int main()
{

	Solution s;
	int a[] = {1, 2, 3, 4, 5, 6};
	//ListNode *lst = makeList(a, 6);
	ListNode *lst = makeList(a, 1);

	pr(lst);
	pr(s.removeNthFromEnd(lst, 1));

	return 0;
}
			
