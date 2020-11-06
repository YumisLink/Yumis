#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 100010
int qwe;
int n;
bool k[4000];
bool cmp(int q)
{
    int cnt = 0;
    for (int i = q; i <= 4 * n; i += 2)
    {
        if (!k[i])
            cnt++;
    }
    if (cnt < n)
        return true;
    else
        return false;
}
int main()
{
    scanf("%d", &qwe);
    for (int www = 1; www <= qwe; www++)
    {
        scanf("%d", &n);
        if (n == 1)
        {
            puts("1");
            continue;
        }
        int start = 2;
        memset(k, 1, sizeof(k));
        while (cmp(start))
        {
            start += 2;
            memset(k, 0, sizeof(k));
            for (int i = start; i <= 4 * n; i += 2)
            {
                if (!k[i])
                {
                    for (int j = i * 2; j <= 4 * n; j += i)
                    {
                        k[j] = 1;
                    }
                }
            }
        }
        for (int i = start; i <= 4*n; i += 2)
        {
            if (!k[i])
                printf("%d ",i);
        }
        puts("");
    }
}