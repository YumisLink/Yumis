#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define MOD 10000
int ans[1100][1100];
int main ()
{
    int n,m;
    scanf("%d%d",&n,&m);
    n++;
    for (int i = 2; i <= m; i ++)
        ans[1][i] = 1;

    for (int i = 2; i <= n; i ++)
    {
        if (i%2==0)
        {
            int cnt = 0;
            for (int j = m-1; j >= 1;j--)
            {
                cnt += ans[i-1][j+1];
                cnt = cnt % MOD;
                ans[i][j] = cnt;
            }
        }
        else 
        {
            int cnt = 0;
            for (int j = 2; j <= m;j++)
            {
                cnt += ans[i-1][j-1];
                cnt = cnt % MOD;
                ans[i][j] = cnt;
            }
        }
    }
    printf("%d",max(ans[n][1],ans[n][m]));
}