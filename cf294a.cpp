#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 110;
int n;
int a[MAXN];

int main()
{
	int x, y;
	int m;

	while (scanf ("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
			scanf ("%d", &a[i]);

		scanf ("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf ("%d %d", &x, &y);
			a[x - 1] += y - 1;
			a[x + 1] += a[x] - y;
			a[x] = 0;
		}

		for (int i = 1; i <= n; i++)
			printf ("%d\n", a[i]);

	}

	return 0;
}
