#include <cstdio>
#define ll long long
#define Max 202100000000
ll a[1000];
int main()
{
    a[1] = 1, a[2] = 2;
    for (int i = 3; i <= 100; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        if (a[i] > Max)
        {
            printf("%d", i);
            return 0;
        }
    }
}