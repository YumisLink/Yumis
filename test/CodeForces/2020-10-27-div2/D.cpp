#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define MAXN 100010
using namespace std;
int k[MAXN], d1[MAXN];
bool cmp(const int a, const int b) { return a > b; }
int main()
{
    int qwe;
    scanf("%d", &qwe);
    for (int www = 1; www <= qwe; www++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &k[i]);
        int len = 1, mi = k[2];
        for (int i = 3; i <= n; i++)
        {
            if (k[i] <= mi)
            {
                len++;
                mi = k[i];
            }
            else
            {
                mi = k[i];
            }
        }
        printf("%d\n", len);
    }
}