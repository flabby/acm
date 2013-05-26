/*
   Reverse Linked List II
   */
#include "header.h"

class Solution
{
	public:
		ListNode *reverseBetween(ListNode *head, int m, int n)
		{
			if (m == n) return head;

			ListNode *hp = new ListNode(0);
			hp->next = head;

			ListNode *p = hp;
			for (int i = 0; i < m - 1; i++)
				p = p->next;
			
			ListNode *pn = p->next;
			for (int i = 0; i < n - m; i++)
			{
				ListNode *q = pn->next;
				pn->next = q->next;
				q->next = p->next;
				p->next = q;
			}

			return hp->next;
		}
};

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	ListNode *lst = makeList(a, 5);
	prList(lst);

	Solution s;
	ListNode *ret = s.reverseBetween(lst, 2, 4);
	prList(ret);

	return 0;
}
			
