#include <cstdio>
#include <cmath>
using namespace std;
int n, cnt, cnt1, cnt2;
int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int l;
        scanf("%d", &l);
        if (l >= 85)
            cnt2++;
        if (l >= 60)
            cnt1++;
        cnt++;
    }
    char ch = '%';
    printf("%d%c\n%d%c", (int)round(((float)cnt1 * 100) / (float)cnt), ch, (int)round(((float)cnt2 * 100) / (float)cnt), ch);
}

