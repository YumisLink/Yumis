#include<cstdio>
#define MAXN 1001000
bool sum[MAXN];
int ans,a,b,c,n;
int main ()
{
    scanf("%d",&n);
    scanf("%d%d%d",&a,&b,&c);
    for (int i = 2; i <= n; i += a)
        sum[i] = true;
    for (int i = 3; i <= n; i += b)
        sum[i] = true;
    for (int i = 3; i <= n; i += c)
        sum[i] = true;
    for (int i = 1; i <= n ; i++)
        if (!sum[i]) ans ++;
    printf("%d",ans);
}