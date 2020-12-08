#include <cstdio>
#define MAXN 110
int x1, x2, y1, y2;
int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int main() {
    scanf("%d%d", &x1, &y1);
    for (int i = 1; i <= x1; i++)
        for (int j = 1; j <= y1; j++)
            scanf("%d", &a[i][j]);
    scanf("%d%d", &x2, &y2);
    for (int i = 1; i <= x2; i++)
        for (int j = 1; j <= y2; j++)
            scanf("%d", &b[i][j]);
    for (int i = 1; i <= x1; i++)
        for (int j = 1; j <= y2; j++)
            for (int k = 1; k <= x2; k++)
                c[i][j] += a[i][k] * b[k][j];
    for (int i = 1; i <= x1; i++) {
        for (int j = 1; j <= y2; j++)
            printf("%d ", c[i][j]);
        puts("");
    }
}