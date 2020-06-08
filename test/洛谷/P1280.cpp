#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 100010
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
int n,k,head,dp[MAXN];
bool tag[MAXN];
struct mark{int start,end;}a[MAXN];
bool cmp(const mark a,const mark b){return a.start > b.start;}
int main ()
{
    freopen("a.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= k; i++)
    {
        int q;
        scanf("%d%d",&a[i].start,&a[i].end);
        tag[a[i].start] = 1;
    }
    memset(dp,0,sizeof(dp));
    sort(a+1,a+1+k,cmp);
    head = 1;
    // for (int i = 1; i <= k; i++)
    // {
    //     printf("*%d %d\n",a[i].start,a[i].end);
    // }
    for (int i = n; i >= 1; i --)
    {
        if (!tag[i]) dp[i] = dp[i+1] + 1;
        else while (a[head].start == i)
        {
            dp[i] = max(dp[i],dp[i+a[head].end]);
            head ++;
        }
    }
    for (int i = 1; i <= n; i ++)
        printf("%d ",dp[i]);
    puts("");
    printf("%d",dp[1]);
    return 0;
}