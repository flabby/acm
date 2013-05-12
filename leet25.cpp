/*
   Reverse Nodes in k-Group
   */
#include "header.h"

class Solution 
{
	public:
		bool moveK(ListNode *p, int k)
		{
			for (int i = 1; i < k; i++)
				if (p->next != NULL)
					p = p->next;
				else
					return false;
			return true;
		}

		ListNode *reverseKGroup(ListNode *head, int k)
		{
			if (head == NULL || k < 2)
				return head;

			ListNode *p = head;
			ListNode *q = NULL;
			ListNode *ret = NULL;
			ListNode *retLast = NULL;

			while (p != NULL && moveK(p, k))
			{
				ListNode *r = NULL;
				ListNode *rLast = NULL;
			//	cout << "p->val=" << p->val << "\n";

				for (int i = 0; i < k; i++)
				{
					ListNode *tmp = p;

					p = p->next;

					tmp->next = r;
					r = tmp;
					if (i == 0)
						rLast = r;
				}

				if (ret == NULL)
					ret = r;
				else
					retLast->next = r;

		//		if (p != NULL)
		//			cout << "  p->val=" << p->val << "\n";
		//		cout << "r ----\n";
		//		prList(r);
		//		cout << "ret ---- \n";
		//		prList(ret);
				retLast = rLast;
			}

			if (p != NULL && retLast != NULL)
				retLast->next = p;
			if (ret == NULL)
				ret = head;
			return ret;
		}
};

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	Solution s;
	ListNode *al = makeList(a, 2);
	prList(al);

	ListNode *ret = s.reverseKGroup(al, 2);
	prList(ret);

	return 0;
}
