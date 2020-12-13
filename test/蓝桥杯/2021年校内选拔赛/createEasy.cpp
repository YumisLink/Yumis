#include <bits/stdc++.h>
#define rd1(a, b) ((rand() * rand()) % (b - a + 1) + a)
using namespace std;

int rp[5010][5010], pt[5010][5010];
int add_x[10] = {0, -1, -1, -1, 0, 0, 0, 1, 1, 1};
int add_y[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int len, wit, cnt;
int main()
{
    freopen("0.in", "w", stdout);
    srand(1561815);
    cnt = rd1(20, 20);
    len = rd1(9, 9);
    wit = rd1(9, 9);
    for (int i = 1; i <= cnt; i++)
    {
        int x = rd1(1, len);
        int y = rd1(1, wit);
        if (pt[x][y] == 1)
        {
            cnt++;
            continue;
        }
        pt[x][y]++;
        for (int j = 1; j <= 9; j++)
            rp[x + add_x[j]][y + add_y[j]]++;
    }

    printf("%d %d\n", len, wit);
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= wit; j++)
            printf("%d ", pt[i][j]);
        puts("");
    }
    printf("%d %d\n", len, wit);
    for (int i = 1; i <= len; i++)
    {
        for (int j = 1; j <= wit; j++)
            printf("%d ", rp[i][j]);
        puts("");
    }
}