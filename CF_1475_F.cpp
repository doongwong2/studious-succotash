#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 700;

template<typename T>inline void read(T& a) {
	char c = getchar();
	T x = 0, f = 1;
	while (!isdigit(c)) { if (c == '-')f = -1; c = getchar(); }
while (isdigit(c)) { x = (x << 1) + (x << 3) + c - '0'; c = getchar(); }a = f * x;}

ll n, m, p;
ll c[1005][1005];
char s[MAXN];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		read(n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s + 1);
			for (int k = 1; k <= n; k++)c[i][k] = s[k] - '0';
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", s + 1);
			for (int k = 1; k <= n; k++)c[i][k] ^= s[k] - '0';
		}
		int flag = 0;
		for (int i = 2; i <= n; i++)
		{
			for (int k = 2; k <= n; k++)
			{
				if (c[1][k] ^ c[i][1] ^ c[1][1] ^ c[i][k]) flag = 1;
			}
		}
		printf("%s\n", flag ? "NO" : "YES");
	}

	return 0;
}