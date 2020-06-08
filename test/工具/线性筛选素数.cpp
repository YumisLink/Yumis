#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000010
#define min(a,b) ((a)<(b)?(a):(b))
bool x[20000010];
bool pd_h(int x)
{
    int y = x,num = 0;
    while (y != 0)
    {
        num = num * 10 + y % 10;
        y /= 10;
    } 
    if (num == x) return 1;
    else return 0;
}
int main ()
{
    int a,b;
    scanf("%d%d",&a,&b);   
    x[1] = true;
    int kk = min(b,MAXN);
    for (int i = 3; i <= kk; i+=2)
        if (!x[i])
        {
            for (int j = i;j <= MAXN;j += i)
                x[j] = true;
            if (i >= a)
                if (pd_h(i))
                    printf("%d\n",i);
        }
}