#include<cstdio>
#define MAXN 100010
#define max(a,b) ((a)>(b)?(a):(b))
int n,k[MAXN],ans,ma;
int main ()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d",&k[i]);
    }
    for (int i = 1; i <= n; i ++)
        ans ^= k[i];
    for (int i = 1; i <= n; i++)
    {
        ans ^= k[i];
        ma = max(ans,ma);
        ans ^= k[i];
    }
    printf("%d\n",ma);
}