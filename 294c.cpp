/*
PROB:Shaass and Lights codeforces 294c
DESC:编号1到n的灯 m个是亮的 每次只能相邻有亮灯才能打开新的灯 问有多少种方法让灯全亮 % (10^9 + 7)
SOLU: 组合公式
	考虑每个亮灯隔成的区段：
	最两端只有一种；
	中间的2^(len(i) - 1)种；
	然后，考虑n-m个灭灯的 排列 C(n - m, len(m-1)), C(n - m - len(m-1), len(m-2)) ... C(len(1), len(1))
	ans = C(len(0), len(0)) * C(len(0)+len(1), len(1)) * 2^(len(1) -1)
	 * ( C(sum(len(1)..len(i)), len(i))) * 2^(len(i) - 1) ).. * C(n-m,len(m))
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long lint;
const int MAXN = 1010;
const lint MOD = 1000000007;

int main()
{
	lint n, m;
	lint C[MAXN][MAXN];
	lint ans = 1;
	lint a[MAXN];
	lint pow[MAXN];

	scanf ("%lld  %lld", &n, &m);
	for (int i = 0; i < m; i++)
		scanf ("%lld", &a[i]);

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i) C[i][j] = 1LL;
			else
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}

	pow[0] = 1;
	pow[1] = 1;
	for (int i = 2; i <= n; i++)
		pow[i] = (pow[i - 1] * 2LL) % MOD;

	sort (a, a + m);
	lint sum = 0;
	lint len;
	for (int i = 0; i < m; i++)
	{
		if (i == 0) len = a[0] - 1;
		else
		{
			len = a[i] - a[i - 1] - 1;
			ans = (ans * pow[len]) % MOD;
		}

		sum += len;
		ans = (ans * C[sum][len]) % MOD;
//		printf ("i=%d ans=%lld\n", i, ans);
	}
	ans = ans * C[n - m][n - a[m - 1]] % MOD;
	printf ("%lld\n", ans);

	return 0;
}

