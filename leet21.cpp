/*
   Merge Two Sorted Lists
   */
#include "header.h"

class Solution
{
	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
		{
			ListNode *ret = NULL;
			ListNode *last = NULL;

			while (l1 != NULL || l2 != NULL)
			{
				ListNode *p(NULL);
				
				if (l2 == NULL || (l1 != NULL && l1->val < l2->val))
				{
					p = l1;
					l1 = l1->next;
				}
				else 
				{
					p = l2;
					l2 = l2->next;
				}

				p->next = NULL;
				if (last == NULL)
					last = p;
				else
				{
					last->next = p;
					last = p;
				}

				if (ret == NULL)
					ret = last;
			}

			return ret;
		}
};

int main()
{
	int a[] = {1, 2, 3, 5};
	int b[] = { 4, 6, 7, 8};
	ListNode *lst1 = makeList(a, 4);
	ListNode *lst2 = makeList(b, 4);
	prList(lst1);
	prList(lst2);

	Solution s;
	ListNode *ret = s.mergeTwoLists(lst1, lst2);
	prList(ret);

	return 0;
}
