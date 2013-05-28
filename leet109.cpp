/*
   Convert Sorted List to Binary Search Tree
   */
#include "header.h"

class Solution
{
	public:
		TreeNode *sortedListToBST(ListNode *head)
		{
			int len = 0;
			for (ListNode *p = head; p != NULL; p = p->next, len++);
			
			return dfs(head, 0, len - 1);
		}

		TreeNode *dfs(ListNode *&list, int l, int r)
		{
			if (l > r)
				return NULL;

			int mid = (l + r) >> 1;
			TreeNode *left = dfs(list, l, mid - 1);
			TreeNode *p = new TreeNode(list->val);
			p->left = left;
			list = list->next;

			p->right = dfs(list, mid + 1, r);
			return p;
		}
};

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	ListNode *lst = makeList(a, 7);

	Solution s;
	TreeNode *root = s.sortedListToBST(lst);
	prTree(root);

	return 0;
}
			
