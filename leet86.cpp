/*
   Partition List
   */
#include "header.h"

class Solution 
{
	public:
		ListNode *partition(ListNode *head, int x)
		{
			if (head == NULL || head->next == NULL)
				return head;

			ListNode *p = head;
			ListNode *q = head;
			ListNode *ppre = NULL;
			ListNode *qpre = NULL;
			ListNode *ret = NULL;

			while (q != NULL)
			{
				if (q->val < x)
				{
					if (p != q) 
					{
						if (ppre != NULL)
							ppre->next = q;
						else
							ret = q;

						ListNode *tmp = q->next;
						if (qpre != NULL)
							qpre->next = q->next;
						
						q->next = p;

						ppre = q;
						q = tmp;
					}
					else
					{
						if (ppre == NULL)
							ret = p;

						ppre = p;
						p = p->next;

						qpre = q;
						q = q->next;
					}
				}
				else
				{
					if (ret == NULL)
						ret = p;
					qpre = q;
					q = q->next;
				}

//				prList(ret);
//				puts("");
			}

			return ret;
		}
};

int main()
{
	int a[] = {1, 4, 3, 2, 5, 2};
	ListNode *lst = makeList(a, 6);

	prList(lst);

	Solution s;
	ListNode *ret = s.partition(lst, 3);

	prList(ret);

	return 0;
}



