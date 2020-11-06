#include <cstdio>
#include <cstring>
#define MAXN 1000010
int kmp[MAXN];
char a[MAXN], b[MAXN];
int main()
{
    scanf("%s%s", a + 1, b + 1);
    int la = strlen(a + 1);
    int lb = strlen(b + 1);
    int j = 0;
    kmp[1] = 0;
    for (int i = 2; i <= lb; i++)
    {
        while (j > 0 && b[i] != b[j + 1])
            j = kmp[j];
        if (b[i] == b[j + 1])
            j++;
        kmp[i] = j;
    }
    j = 0;
    for (int i = 1; i <= la; i++)
    {
        while (j > 0 && a[i] != b[j + 1])
            j = kmp[j];
        if (a[i] == b[j + 1])
            j ++;
        if (lb == j)
        {
            printf("%d\n",i-lb+1);
            j = kmp[j];
        }
    }
    for (int i = 1; i < lb; i ++)
        printf("%d ",kmp[i]);
    printf("%d",kmp[lb]);
}