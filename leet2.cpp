#include <iostream>
using namespace std;

#include <limits.h>
#include <cmath>
#include <cstdio>

class Solution {
public:
	void pr(int A[], int n)
	{
		puts ("------------------------");
		for (int i = 0; i < n; i++)
			printf ("%d ", A[i]);
		printf ("\n------------------------\n");
	}

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m < n) 
            return findMedian(A, B, 0, m - 1, m, n);
        else 
            return findMedian(B, A, 0, n - 1, n, m);
    }
    
    double findMedian(int A[], int B[], int l, int r, int nA, int nB)
    {
        if (l > r)
	//		return findMedian(B, A, 0, nB - 1, nB, nA);
            return findMedian(B, A, max(0, (nA + nB) / 2 - nA),
                min(nB, (nA + nB) / 2), nB, nA);
        
        int i = (l + r) / 2;
        int j = (nA + nB) / 2 - i - 1;
        
    //    printf ("nA=%d nB=%d i=%d j=%d\n", nA, nB, i, j);
	//	pr(A, nA);
	//	pr(B, nB);
       // char ch;
       // scanf ("%c", &ch);
        
        if (j >= 0 && A[i] < B[j])
            return findMedian(A, B, i + 1, r, nA, nB);
        else if (j < nB - 1 && A[i] > B[j + 1])
            return findMedian(A, B, l, i - 1, nA, nB);
        else
        {
    //        printf (" here i=%d j=%d\n", i, j);
            if ((nA + nB) % 2 == 1)
                return A[i];

			int k;
			if (i > 0)
				k = max(A[i - 1], j >= 0 ? B[j] : INT_MIN);
			else
				k = B[j];
             return (A[i] + k) / 2.0;
        }
    }
};

int main() {
    int a[] = {4};
    int b[] = {1, 2, 3, 4};
    
    class Solution s;
    cout << s.findMedianSortedArrays(a, 0, b, 4) << endl << endl;
 //   cout << s.findMedianSortedArrays(a, 1, b, 3) << endl;
 //   
 //   int c[] = {1, 2, 3, 4, 5};
 //   int d[] = {6};
 //   cout << s.findMedianSortedArrays(c, 5, d, 1);

    return 0;
}
