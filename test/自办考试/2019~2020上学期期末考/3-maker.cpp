#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((rand()*rand()) % ((b)-(a)+1) + (a)) 
int n,m;
int main ()
{
    freopen("FFT.in","w",stdout);
    srand((int)time(0));
    m = n = 500000;
    printf("%d %d\n",n,m);
    for (int i = 1; i <= n; i ++)
        printf("%d ",random(1,10000000));
        puts("");
    for (int i = 1; i <= m; i ++)
    {
        int a = random(1,n),b = random(1,n);
        printf("%d %d\n",min(a,b),max(a,b));
    }
}