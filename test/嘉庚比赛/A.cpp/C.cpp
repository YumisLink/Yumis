#include<cstdio>
#define MAXN 100010
int k,n,m;
int ans[10][MAXN];
int main ()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d",&k);
        for (int j = 0; j <= 9; j ++)
            ans[j][i] = ans[j][i-1];
        ans[k][i] ++;
    }
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",ans[c][b] - ans[c][a-1]);
    }
    
}