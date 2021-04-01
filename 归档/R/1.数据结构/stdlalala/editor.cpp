#include<bits/stdc++.h>
using namespace std;
const int N=500500;
template <typename T> class stack_BIT
{
	T a[N],t[N];
	int capacity,pos;
	void add(int p,T c)
	{
		for(; p<=capacity; p+=p&(-p))
			t[p]+=c;
	}
	T presum(int p) const
	{
		T s=0;
		for(; p; p-=p&(-p))
			s+=t[p];
		return s;
	}
	public:
	void init(int n)
	{
		capacity=n;
		pos=0;
		fill(a,a+N,0);
		fill(t,t+N,0);
	}
	void push(T x)
	{
		++pos;
		add(pos,x);
		a[pos]=x;
	}
	void pop()
	{
		add(pos,-a[pos]);
		a[pos--]=0;
	}
	T top() const
	{
		return a[pos];
	}
	void change(int p,T c)
	{
		add(p,c-a[p]);
		a[p]=c;
	}
	T sum(int l,int r) const
	{
		return presum(r)-presum(l-1);
	}
	int size() const
	{
		return pos;
	}
	bool empty() const
	{
		return pos==0;
	}
};
stack_BIT<long long> pre,suf;
int n;
int main()
{
	freopen("editor.in","r",stdin);
	freopen("editor.out","w",stdout);
	scanf("%d",&n);
	pre.init(n);
	suf.init(n);
	char ch;
	int a,b;
	for(int i=1;i<=n;++i)
	{
		scanf("\n%c",&ch);
		if(ch=='I')
		{
			scanf("%d",&a);
			pre.push(a);
		}
		if(ch=='D')
			pre.pop();
		if(ch=='L' && !pre.empty())
		{
			suf.push(pre.top());
			pre.pop();
		}
		if(ch=='R' && !suf.empty())
		{
			pre.push(suf.top());
			suf.pop();
		}
		if(ch=='Q')
		{
			scanf("%d%d",&a,&b);
			int s1=pre.size(),s2=suf.size();
			if(b<=s1)
				printf("%I64d\n",pre.sum(a,b));
			else
				if(a>s1)
					printf("%I64d\n",suf.sum(s2-(b-s1-1),s2-(a-s1-1)));
				else
					printf("%I64d\n",pre.sum(a,s1)+suf.sum(s2-(b-s1-1),s2));
		}
		if(ch=='C')
		{
			scanf("%d%d",&a,&b);
			int s1=pre.size(),s2=suf.size();
			if(a<=s1)
				pre.change(a,b);
			else
				suf.change(s2-(a-s1-1),b);
		}
	}
}
