#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 100010
using namespace std;
int ans,dp[MAXN],n;
char ch[MAXN];
int main ()
{
    // freopen("a","r",stdin);
    scanf("%s",&ch);
    //printf("%s",ch);
    int n = strlen(ch);
    if (ch[0] == '0') dp[0] = 1;
    else dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (ch[i] == '0')
            dp[i] = dp[i-1]+1;
        if (ch[i] == '1')
        {
            dp[i] = dp[i-1]-1;
            if (dp[i] < 0)
                dp[i] = 0;
        }
        ans = max(ans,dp[i]);
    }
    // for (int i = 0; i < n; i ++)
	// 	printf("%d ",dp[i]);
	// puts(""); 
    if (ans == 0) printf("-1");
    else   printf("%d",ans);
}