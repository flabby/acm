/*
   sudoku
   dancing link
   */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int INF = (1<<30);
const int SIZE = 3; //sub grid size
const int N = 9	;	//size of sudoku
const int N2 = N * N; // 2 dimesion size
const int N3 = N2 * N; // 3 dimesions

const int ROW_NUM = N3; //
const int COL_NUM = N2 * 4;
const int MAXN = ROW_NUM * COL_NUM + COL_NUM + 10;
const int MAXR = ROW_NUM + 10;

int n, m;
int L[MAXN], R[MAXN], U[MAXN], D[MAXN];
int C[MAXN], O[MAXN], S[MAXN], H[MAXR];
int record[MAXR], ans[MAXR];
int nodeCnt, recordCnt;
char g[N2 + 10];

void init()
{
//	printf ("ROW_NUMBER=%d COL_NUM=%d\n", ROW_NUM, COL_NUM);
	//前COL_NUM 记录每列的情况
	for (int i = 0; i <= COL_NUM; i++)
	{
		L[i] = i - 1;   //left pointer
		R[i] = i + 1;	//right pointer
		U[i] = i; 		//up pointer
		D[i] = i;		//down pointer
		C[i] = i;		//col header pointer
		O[i] = 0;		//record the search result
		S[i] = 0;		//the total number of node in the list
	}
	L[0] = COL_NUM;
	R[COL_NUM] = 0;
	nodeCnt = COL_NUM + 1;
	recordCnt = 0;
	memset(H, 0, sizeof(H)); //row header pointer
}

void insert(int i, int j)
{
	if (H[i])
	{
		L[nodeCnt] = L[H[i]];
		R[nodeCnt] = H[i];
		L[R[nodeCnt]] = nodeCnt;
		R[L[nodeCnt]] = nodeCnt;
	}
	else
	{
		L[nodeCnt] = nodeCnt;
		R[nodeCnt] = nodeCnt;
		H[i] = nodeCnt;
	}
	U[nodeCnt] = U[j];
	D[nodeCnt] = j;
	U[D[nodeCnt]] = nodeCnt;
	D[U[nodeCnt]] = nodeCnt;
	C[nodeCnt] = j;
	O[nodeCnt] = i;
	++S[j];
	++nodeCnt;
}
void add(int i, int j, int k)
{
	int row = i * N2 + j * N + k + 1;
	insert(row, i * N + j + 1);  			//A[i,j] 有且仅有一个数字 共N2个
	insert(row, i * N + k + N2 + 1);		//row i 有且仅有一个k 共N2个
	insert(row, j * N + k + 2 * N2 + 1); 	//col j 有且仅有一个k 共N2个
	insert(row, (i / SIZE * SIZE + j / SIZE) * N + k + N2 * 3 + 1);	//sub grid 有且仅有一个k 共N2个
}

void build()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int id = i * N + j;
			if (g[id] >= '0' && g[id] <= '9')
				add(i, j, g[id] - '1');
			else
			{
				for (int k = 0; k < N; k++)
					add(i, j, k);
			}
		}
}
void remove(int c)
{
	L[R[c]] = L[c];
	R[L[c]] = R[c];
	for (int i = D[c]; i != c; i = D[i])
		for (int j = R[i]; j != i; j = R[j])
		{
			U[D[j]] = U[j];
			D[U[j]] = D[j];
			--S[C[j]];
		}
}

void resume(int c)
{
	for (int i = U[c]; i != c; i = U[i])
		for (int j = L[i]; j != i; j = L[j])
		{
			++S[C[j]];
			D[U[j]] = j;
			U[D[j]] = j;
		}

	R[L[c]] = c;
	L[R[c]] = c;
}


bool dfs(int k)
{
	if (!R[0])
	{
		recordCnt = k;
		return true;
	}
	int cnt = INF, c;
	for (int i = R[0]; i; i = R[i])
		if (S[i] < cnt)
		{
			cnt = S[i];
			c = i;
			if (cnt == 1)
				break;
		}
	
	remove(c);
	for (int i = D[c]; i != c; i = D[i])
	{
		for (int j = R[i]; j != i; j = R[j])
			remove(C[j]);
		record[k] = O[i];
		if (dfs(k + 1))
			return true;

		for (int j = L[i]; j != i; j = L[j])
			resume(C[j]);
	}
	resume(c);
	return false;
}

void output()
{
	for (int i = 0; i < recordCnt; i++)
		ans[(record[i] - 1) / N] = (record[i] - 1) % N + 1 + '0';
	for (int i = 0; i < N2; i++)
		printf ("%c", (char)ans[i]);
	printf ("\n");
}

int main()
{
	while (gets(g))
	{
		if (g[0] == 'e') break;

		init();
		build();
		dfs(0);
		output();
	}

	return 0;
}

