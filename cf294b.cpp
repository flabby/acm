#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 110;

struct node
{
	int x, y;
}a[MAXN];

int sumx = 0;
int sumy = 0;
int f[MAXN * 2];
int n;

bool zeroOnePack(int v)
{
	memset(f, -1, sizeof(f));
	f[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = v; j >= a[i].x; j--)
			if (f[j] < f[j - a[i].x] + a[i].y)
				f[j] = f[j - a[i].x] + a[i].y;
	}

//	for (int i = 0; i <= v; i++)
//		printf ("f[%d]=%d\n", i, f[i]);
//	printf ("ret=%d\n", v >= (sumy - f[v]));
//	puts ("");

	return v >= (sumy - f[v]);
}

int main()
{
	while (scanf ("%d", &n) != EOF)
	{
		sumx = sumy = 0;
		for (int i = 0; i < n; i++)
		{
			scanf ("%d %d", &a[i].x, &a[i].y);
			sumx += a[i].x;
			sumy += a[i].y;
		}

		int i;
		for (i = 1; i <= sumx; i++)
			if (zeroOnePack(i))
				break;
		printf ("%d\n", i);
	}

	return 0;
}


