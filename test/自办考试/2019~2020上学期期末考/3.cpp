#include<cstdio>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 500010
#define lg(a) (int)(log(a)/log(2))
int f[MAXN][40],n,m;
int ksm(int base,int b)
{
    int ans = 1;
    while(b)
    {
        if(b&1) b *= base;
        base *= base;
        b <<= 1;
    }
    return ans;
}
int main ()
{
    freopen("FFT.in","r",stdin);
    freopen("FFT10.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i ++)
        scanf("%d",&f[i][0]);
    int to = log2(n);
    for (int i = 1; i <= to; i ++)
        for (int j = 1; j + (1<<i) <= n+1; j ++)
            f[j][i] = max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
    for (int i = 1; i <= m; i ++)
    {
        int q,w;
        scanf("%d%d",&q,&w);
        int mid = (int)lg(w-q+1);
        printf("%d\n",max(f[q][mid],f[w-(1 << mid) + 1][mid]));
    }
}