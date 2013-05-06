/*
   Merge k Sorted Lists
   bug 1 *it == NULL
   bug 2 vector iterator  lists.erase(it) don't need it++

   */

#include "header.h"

class comp
{
	public:
		bool operator() (const ListNode *l, const ListNode *r) const
		{
			return (l->val > r->val);
		}
};

class Solution
{
	public:
		ListNode *mergeKLists(vector<ListNode *> &lists)
		{
			vector<ListNode *>::iterator it;
			for (it = lists.begin(); it != lists.end(); )
				if (*it == NULL)
					lists.erase(it);
				else
					it++;

		//	cout << lists.size() << endl;

			if (lists.size() < 1) return NULL;

			make_heap(lists.begin(), lists.end(), comp());

			ListNode *head = NULL;
			ListNode *last = NULL;

			while (lists.size() > 0)
			{
				if (head == NULL)
				{
					last = lists[0];
					head = last;
				}
				else
				{
					last->next = lists[0];
					last = last->next;
				}
				
				pop_heap(lists.begin(), lists.end(), comp());

				int id = lists.size() - 1;
				if (lists[id]->next != NULL)
				{
					lists[id] = lists[id]->next;
					push_heap(lists.begin(), lists.end(), comp());
				}
				else
					lists.pop_back();

			}

			return head;
		}

};


int main()
{
	vector<ListNode *> d;
	d.push_back(NULL);
	Solution s;
	prList(s.mergeKLists(d));

	int a[] = { 1, 4, 7, 11};
	ListNode *al = makeList(a, 4);
	prList(al);
	d.push_back(al);

	int b[] = { 2, 5, 8, 11};
	ListNode *bl = makeList(b, 4);
	prList(bl);
	d.push_back(bl);

	int c[] = { 3, 6, 9, 11};
	ListNode *cl = makeList(c, 4);
	prList(cl);
	d.push_back(cl);

	prList(s.mergeKLists(d));

	return 0;
}
