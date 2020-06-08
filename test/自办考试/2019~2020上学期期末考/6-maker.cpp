#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((rand()*rand()) % ((b)-(a)+1) + (a)) 
int main ()
{
    freopen("lscs.in","w",stdout);
    srand(int(time(0)));
    int n = random(1000000,5000000);
    int m = random(1000000,5000000);
    printf("%d %d\n",n,m);
    for (int i = 1; i <= n ; i ++)
        printf("%d ",random(1,30000));
}