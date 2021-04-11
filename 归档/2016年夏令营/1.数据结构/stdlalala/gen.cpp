#include<bits/stdc++.h>
using namespace std;
const int V=1000000000;
int n=10000;
int randint(int l,int r)
{
	long long x=rand();
	x=x*32768+rand();
	x=x*32768+rand();
	return x%(r-l+1)+l;
}
int main()
{
	srand(time(0));
	freopen("editor.in","w",stdout);
	cout<<n<<endl;
	int nowl=0,nowp=0;
	for(int i=1;i<=n;++i)
	{
		int type=rand()%7;
		if(type==0 || type==6)
		{
			cout<<'I'<<' '<<randint(-V,V)<<endl;
			++nowl,++nowp;
		}
		if(type==1)
		{
			if(nowp==0)
			{
				--i;
				continue;
			}
			cout<<'D'<<endl;
			--nowl,--nowp;
		}
		if(type==2 || type==3)
		{
			if(nowl==0)
			{
				--i;
				continue;
			}
			int p=randint(0,nowl-1);
			if(p<nowp)
			{
				cout<<'L'<<endl;
				nowp=max(0,nowp-1);
			}
			else
			{
				cout<<'R'<<endl;
				nowp=min(nowl,nowp+1);
			}
		}
		if(type==4)
		{
			if(nowl==0)
			{
				--i;
				continue;
			}
			int l=randint(1,nowl),r=randint(1,nowl);
			if(l>r) swap(l,r);
			cout<<'Q'<<' '<<l<<' '<<r<<endl;
		}
		if(type==5)
		{
			if(nowl==0)
			{
				--i;
				continue;
			}
			int p=randint(1,nowl),v=randint(-V,V);
			cout<<'C'<<' '<<p<<' '<<v<<endl;
		}
	}
	cerr<<"nowp="<<nowp<<" nowl="<<nowl<<endl;
}
