/*
   Remove Duplicates from Sorted List 
   */
#include "header.h"

class Solution
{
	public:
		ListNode *deleteDuplicates(ListNode *head)
		{
			if (head == NULL || head->next == NULL)
				return head;

			ListNode *ret = head;
			ListNode *p = head;
			ListNode *q = NULL;
			while ((q = getNext(p)) != NULL)
			{
				printf ("q->val=%d p->val=%d\n", q->val, p->val);
				p->next = q;
				p = q;
			}
			p->next = NULL;
			return ret;
		}

		ListNode *getNext(ListNode *p)
		{
			if (p == NULL)
				return p;

			int x = p->val;
			ListNode *f = p;
			for (p = p->next; p != NULL && p->val == x; p = p->next)
			{
				f = p;
				delete f;
			}
			return p;
		}
};

int main()
{
	int a[] = {1, 1, 2, 3, 3};
	ListNode *lst = makeList(a, 5);

	Solution s;
	ListNode *ret = s.deleteDuplicates(lst);
	prList(ret);

	return 0;
}
