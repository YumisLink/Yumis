#include<cstdio>
#define min(a,b) ((a)<(b)?(a):b)
#define MAXN 110
#define INF 0x3f3f3f3f
int n,c,t,p[MAXN];
int main ()
{
    int l;
    while(scanf("%d",&l) != EOF)
    {
        double vr,vt1,vt2;
        double dp[MAXN];
        scanf("%d%d%d%lf%lf%lf",&n,&c,&t,&vr,&vt1,&vt2);
        for (int i = 0; i <= 109; i++){dp[i] = INF;p[i] = 0;}
        for (int i = 1; i <= n; i++)
            scanf("%d",&p[i]);
        double mr = c / vt1;
        p[n+1] = l;dp[n+1] = INF;
        dp[0] = 0; p[0] = 0;
        for (int i = 1; i <= n+1; i ++)
        {
            double ky = 0;
            double mmin = INF;
            for (int j = 0; j < i; j++)
            {
                double rang = p[i] - p[j];
                if (rang > c)
                    ky = mr + (rang-c) / vt2;
                else 
                    ky = rang / vt1;
                if (j)
                    ky += t;
                mmin = min(mmin,ky + dp[j]);
            }
            dp[i] = mmin;
        }
        if (dp[n+1] < l/vr)
            puts("What a pity rabbit!");
        else 
            puts("Good job,rabbit!");
        // printf("%lf   %lf\n",dp[n+1],l/vr);
        // for (int i = 0 ; i <= n+1; i ++)
        //     printf("%lf ",dp[i]);
        // puts("");
    }
    return 0;
}