/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

#include <cstdio>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
void pr(ListNode *p)
{
	puts ("--------------------");
	for (; p != NULL; p = p->next)
		printf ("%2d ", p->val);
	printf ("\n-----------------------------\n");
}

ListNode *makeList(int a[], int n)
{
	ListNode *p = NULL;

	for (int i = n - 1; i >= 0; i--)
	{
		ListNode *tmp = new ListNode(a[i]);
		tmp->next = p;
		p = tmp;
	}

	return p;
}

ListNode *sum;
ListNode *plast;
void addToTail(int x)
{
	ListNode *tmp = new ListNode(x);
	if (plast != NULL)
		plast->next = tmp;
	else
		sum = tmp;
	plast = tmp;
}

class Solution {
public:

/*
//when submit the below code needs to be here
ListNode *sum;
ListNode *plast;
void addToTail(int x)
{
    ListNode *tmp = new ListNode(x);
	if (plast != NULL)
		plast->next = tmp;
	else
		sum = tmp;
	plast = tmp;
}*/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		sum = NULL;
		plast = NULL;

        ListNode *tmp;
        
        int r = 0;
        int k = 0;
        int flg = 0;
        
        while (l1 != NULL || l2 != NULL)
        {
			flg = 1;

			int x = 0;
			if (l1 != NULL)
			{
				x = l1->val;
				l1 = l1->next;
			}
			
			int y = 0;
			if (l2 != NULL)
			{
				y = l2->val;
				l2 = l2->next;
			}

            r = k + x + y;
            k = r / 10;
            r %= 10;
            
			addToTail(r);
            printf ("add x=%d y=%d\n", x, y);
        }
        
        if (!flg || k > 0)
        {
			addToTail(k);
        }
        return sum;
    }
};

int main()
{
	int a[] = {1, 8};
	int b[] = {0};

	ListNode *p = makeList(a, 2); 
	ListNode *q = makeList(b, 1);

	pr(p);
	pr(q);

	Solution sol;
	ListNode *s = sol.addTwoNumbers(p, q);
	pr(s);

	return 0;
}
