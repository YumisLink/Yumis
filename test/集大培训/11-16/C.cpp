#include<cstdio>
#define LL long long
LL dp[110];
LL big,small1,small2,small3,small4;
int main ()
{
    big = 1; dp[0] = 1;dp[1] = 1;dp[2] = 2;dp[3] = 3;
    for (int i = 4; i <= 55; i ++)
        dp[i] = dp[i-1] + dp[i-3];
    int a;
    while (scanf("%d",&a))
    {
        if (a == 0) break;
        printf("%lld\n",dp[a]);
    }
}