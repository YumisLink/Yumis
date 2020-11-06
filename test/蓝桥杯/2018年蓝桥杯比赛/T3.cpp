#include<cstdio>
int main(int argc, char const *argv[])
{
    int ans = 1;
    int cnt = 0;
    for (int i = 1; i <= 100; i ++)
    {
        int a;
        scanf("%d",&a);
        ans *= a;
        while(ans%10 == 0)
        {
            cnt ++;
            ans /=10;
        }
        ans %= 1000;
    }
    printf("%d",cnt);
    return 0;
}


//31
