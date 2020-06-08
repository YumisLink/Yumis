#include<cstdio>
#include<algorithm>
#define MAXN 100010
using namespace std;
bool cmp(const int& a, const int& b){return a > b;}
int cnt,n,a[MAXN];
int main()
{
    freopen("a","r",stdin);
    n = 1;
    while(scanf("%d",&a[n++]));
    n--;
    int d1[MAXN],d2[MAXN];
    int cnt = 1;ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if(d1[cnt] >= a[i]) 
            d1[++cnt] = a[i];
        else 
        {
            int k = upper_bound(d1+1, d1+1+n,cmp);
            d1[k-1] = a[i];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if(d2[ans] <= a[i]) 
            d2[++ans] = a[i];
        else 
        {
            int k = upper_bound(d2+1, d2+1+n);
            d2[k-1] = a[i];
        }
    }
    printf("%d\n%d",cnt,ans);
        
}