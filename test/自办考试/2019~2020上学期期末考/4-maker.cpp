#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((rand()*rand()) % ((b)-(a)+1) + (a)) 
int main ()
{
    freopen("yoo.in","w",stdout);
    srand(int(time(0)));
    int m = random(2,999);
    int n = random(m,1000);
    printf("%d %d",n,m);
}