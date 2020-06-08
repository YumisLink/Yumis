#include<cstdio>
int main()
{
    int a,b,c;
    while(scanf("%d/%d/%d",&a,&b,&c) != EOF)
    {
        if (b > 1) c += 31;
        if (b > 2) 
        {
            if (a % 400 == 0 || (a % 100 != 0 && a % 4 == 0))
                c += 29;
            else 
                c += 28;
        }
        if (b > 3) c += 31;
        if (b > 4) c += 30;
        if (b > 5) c += 31;
        if (b > 6) c += 30;
        if (b > 7) c += 31;
        if (b > 8) c += 31;
        if (b > 9) c += 30;
        if (b > 10) c += 31;
        if (b > 11) c += 30;
        printf("%d\n",c);
    }
    return 0;
}