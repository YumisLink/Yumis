#include <cstdio>
#include <algorithm>
#include <cmath>
// #define max(a,b)
using namespace std;
int k[1000];
int main ()
{
    int qwe;
    scanf("%d",&qwe);
    for (int www= 1; www <= qwe; www ++)
    {
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n; i ++)
            scanf("%d",&k[i]);
        sort(k+1,k+n+1);
        int ans = 0x3f3f3f3f;
        printf("***%d\n",ans);
    }
}