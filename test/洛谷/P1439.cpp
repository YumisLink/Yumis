#include <cstdio>
#include<algorithm>
#define MAXN 100010
#define fup(a, b, c) for (int a = b; a <= c; a++)
using namespace std;
int a[MAXN], b[MAXN], c[MAXN], mid[MAXN],ans[MAXN];
// bool cmp(const int a,const int b){return a>b;}
int main()
{
    int n;
    scanf("%d ", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        mid[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        c[i] = mid[b[i]];
    }
    int cnt = 1;
    ans[1] = c[1];
    for (int i = 2; i <= n; i ++)
    {
        if (ans[cnt] <= c[i])
            ans[++cnt] = c[i];
        else 
        {
            int k = upper_bound(ans+1,ans+cnt+1,c[i])-ans;
            ans[k] = c[i];
        }
        fup(j,1,n) 
            printf("%d ",ans[j]);
        puts("");
    }
        printf("%d\n",cnt);
    
}
