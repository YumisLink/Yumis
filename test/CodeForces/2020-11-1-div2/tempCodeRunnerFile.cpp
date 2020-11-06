#include <cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
#define MAXN 100010
int qwe;
int main()
{
    scanf("%d", &qwe);
    for (int www = 1; www <= qwe; www++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",max(a+b,c+d));
    }
}