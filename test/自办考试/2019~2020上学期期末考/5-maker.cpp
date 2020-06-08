#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((rand()*rand()) % ((b)-(a)+1) + (a)) 
int main ()
{
    freopen("tree.in","w",stdout);
    srand(int(time(0)));
    int n = 400000;
    printf("%d\n",n);
    for (int i = 1; i <= n ; i ++)
        printf("%d ",random(1,10000000));
}