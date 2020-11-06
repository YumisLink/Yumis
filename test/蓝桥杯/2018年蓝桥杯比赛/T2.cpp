#include<cstdio>
int a,b;
void print(int x)
{
    bool a[10];
    for (int i = 8; i >= 1; i --)
    {
        a[i] = x&1;
        // printf("%c",x&1?'+':'-');
        x >>= 1;
    }
    for (int i = 1; i <= 8 ; i ++)  printf("%c",a[i]?'+':' ');
}
int main()
{
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 16; j++)
    //     {
    //         scanf("%d",&b);print(b);
    //         scanf("%d",&b);print(b);
    //         puts("");
    //     }
    //     puts("");
    // }
    long long k;
    k = 9;
    for (int i =1 ; i <= 8; i ++)
        k *= 9,printf("%lld\n",k);
    
    return 0;
    //387420489
}
