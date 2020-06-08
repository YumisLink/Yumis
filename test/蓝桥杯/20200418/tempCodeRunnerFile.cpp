#include<cstdio>
int main()
{
    int a[100],n,m,k,ans = 0;
    scanf("%d",&n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d",&m);
		if (m > ans)
		{
			ans = m;
			k = i;
		}
	}
	printf("%d %d",ans,k);
}