/*
   Swap Nodes in Pairs
   */
#include "header.h"

class Solution
{
	public:
		ListNode *swapPairs(ListNode *head)
		{
			if (head == NULL || head->next == NULL)
				return head;

			ListNode  *nn = swapPairs(head->next->next);

			ListNode *r = head->next;

			r->next = head;
			head->next = nn;

			return r;
		}
};

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	ListNode *al = makeList(a, 6);
	
	Solution s;
	prList(s.swapPairs(al));

	return 0;
}
