#include<cstdio>
#include<algorithm>
bool cmp (const int a, const int b){return a>b;}
int main()
{
    int a[100],n,m,k,ans = 0;
    scanf("%d",&n);
	for (int i = 0; i < n; i ++)
	{
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n,cmp);
	for (int i = 0; i < n-1 ; i ++)
	{
		printf("%d ",a[i]);
	}
	printf("%d",a[n-1]);
}