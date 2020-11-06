#include<cstdio>
int main()
{
    int ans = 0;
    int k = 1000;
    while (k)
    {
        k >>= 1;
        ans ++;
    }
    printf("%d",ans);
    return 0;
}