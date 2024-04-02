#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>
 
using namespace std;
 
int n, a[100010];
bool flag = false;
 
int main()
{
    scanf("%d", &n);
    scanf("%d", &a[1]);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % a[1] != 0)
            flag = 1;
    }
    if (flag)
        printf("-1\n");
    else
    {
        printf("%d\n", n * 2);
        for (int i = 1; i <= n; i++)
            printf("%d %d ", a[i], a[1]);
    }
 
    return 0;
}
