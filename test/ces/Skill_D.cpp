#include <cstdio>
int gcd(int a,int b) { return (b == 0) ? a : gcd(b, a % b); }
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n",a / gcd(a,b) * b);
}