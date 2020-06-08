#include<cstdio>
#define LL long long 
LL dp[35];
int main()
{
    dp[1] = 2;
    for (int i = 2; i <= 35; i++)
        dp[i] = dp[i-1] * 3+2;
    int a;
    while(scanf("%d",&a) != EOF)
        printf("%lld\n",dp[a]);
}