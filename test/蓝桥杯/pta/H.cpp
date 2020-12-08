#include <cstdio>
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", (n + 2 > 7) ? (n + 2 - 7) : (n + 2));
}