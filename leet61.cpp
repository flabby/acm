/*
   Rotate List
   */
#include "header.h"

class Solution 
{
	public:
		ListNode *rotateRight(ListNode *head, int k)
		{
			if (head == NULL)
				return head;

			ListNode *ret = head;
			ListNode *last = head;
			int len = getLen(last);
			
			k %= len;
			if (!k)
				return head;
			k = len - k;

			ListNode *pre = head;
			for (int i = 1; i < k; i++)
				pre = pre->next;

			ret = pre->next;
			pre->next = NULL;
			last->next = head;

			return ret;
		}
		int getLen(ListNode *&p)
		{
			if (p == NULL)
				return 0;

			int ret = 1;
			for (; p->next != NULL; p = p->next)
				ret++;
			return ret;
		}
};

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	ListNode *lst = makeList(a, 5);

	Solution s;
	ListNode *ret = s.rotateRight(lst, 5);
	prList(ret);

	return 0;
}
