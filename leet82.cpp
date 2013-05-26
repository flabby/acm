/*
   Remove Duplicates from Sorted List II
   */
#include "header.h"

class Solution
{
	public:
		ListNode *deleteDuplicates(ListNode *head)
		{
			if (head == NULL || head->next == NULL)
				return head;

			ListNode *ret = NULL;
			ListNode *last = NULL;
			ListNode *p = head;
			ListNode *q = NULL;
			int pre = head->val - 1;
			while ((q = getNext(p, pre)) != NULL)
			{
			//	printf ("q->val=%d p->val=%d\n", q->val, p->val);
				if (last != NULL)
					last->next = q;
				last = q;
				
				if (ret == NULL)
					ret = q;
					
				pre = q->val;
				p = q->next;
				q->next = NULL;
			}
			return ret;
		}

		ListNode *getNext(ListNode *p, int pre)
		{
			if (p == NULL)
				return p;

			int x = p->val;
			ListNode *q = p->next;
			ListNode *f = p;
			while (x == pre || (q != NULL && x == q->val))
			{
				f = p;
				p = q;
				if (p == NULL)
					return NULL;
				q = p->next;
				pre = x;
				x = p->val;
				delete f;
			}
			return p;
		}
};

int main()
{
	int a[] = {1, 2, 2, 3, 3, 4};
	ListNode *lst = makeList(a, 3);

	Solution s;
	ListNode *ret = s.deleteDuplicates(lst);
	prList(ret);

	return 0;
}
