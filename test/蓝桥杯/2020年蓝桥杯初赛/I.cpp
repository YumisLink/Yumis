#include <cstdio>
#include <map>
#define MAXN 1010
using namespace std;
int x[MAXN], y[MAXN];
int main()
{
    int n;
    int cnt = 2;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &x[i], &y[i]);
    int flag = 0;
    for (int i = 2; i <= n; i++)
    {
        flag = 0;
        for (int j = 1; j < i; j++)
            if (x[i] == x[j] && y[i] == y[j])
                flag = 1;
        if (flag)
            continue;
        cnt++;
        map<int, bool> M;
        for (int j = 1; j < i; j++)
        {
            if (x[i] == x[j])
                continue;
            int k = ((y[i] - y[j]) * 1000) / ((x[i] - x[j]) * 1000);
            if (M[k])
            {
                continue;
            }
            else
            {
                M[k] = 1;
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}