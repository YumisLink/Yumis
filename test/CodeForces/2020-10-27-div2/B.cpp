#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int qwe;
    scanf("%d", &qwe);
    for (int www = 1; www <= qwe; www++)
    {
        int n, cnt1 = 0, cnt2 = 0;
        char last;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                scanf("%c", &last);
            char k;
            scanf("%c", &k);
            if (last == k && k == '1')
                cnt1++;
            if (last == k && k == '0')
                cnt2++;
            last = k;
        }
        printf("%d\n", (cnt1 > cnt2 ? cnt1 : cnt2));
    }
}