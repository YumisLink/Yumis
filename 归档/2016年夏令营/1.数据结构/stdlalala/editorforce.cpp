#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int t[N]={},tot=0,pos=0,n;
int main()
{
	freopen("editor.in","r",stdin);
	freopen("editor.ans","w",stdout);
	scanf("%d",&n);
	char ch;
	int a,b;
	for(int i=1;i<=n;++i)
	{
		scanf("\n%c",&ch);
		if(ch=='I')
		{
			scanf("%d",&a);
			++tot;
			++pos;
			for(int i=tot;i>pos;--i)
				t[i]=t[i-1];
			t[pos]=a;
		}
		if(ch=='D')
		{
			for(int i=pos;i<tot;++i)
				t[i]=t[i+1];
			--tot;
			--pos;
		}
		if(ch=='L')
			pos=max(0,pos-1);
		if(ch=='R')
			pos=min(tot,pos+1);
		if(ch=='Q')
		{
			scanf("%d%d",&a,&b);
			long long sum=0;
			for(int i=a;i<=b;++i)
				sum+=t[i];
			printf("%I64d\n",sum);
		}
		if(ch=='C')
		{
			scanf("%d%d",&a,&b);
			t[a]=b;
		}
	}
}
