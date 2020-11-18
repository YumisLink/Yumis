010];
int main()
{
    scanf("%lld%lld", &n, &p);
    ny[1] = 1;
    for (int i = 2; i <= n; ++i)
        ny[i] = (p - p / i) * ny[p % i] % p;
    for (int i = 1; i <= n; i ++)
        printf("%d\n",ny[i]);
}