#include<cstdio>
#define abs(a) ((a)>0?(a):(-a))
#define max(a,b) ((a)>(b)?(a):(b))
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    int a = max(abs(x),abs(y));
    int ans = (1+(a*2-1))*(a*2-1);
    if (y == a) ans += x+a;
    if (x == a) ans += 3*a - y;
    if (y == -a) ans += 5*a - x;
    if (x == -a) ans -= a-y;
    printf("%d",ans);
    
}