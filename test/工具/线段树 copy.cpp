#include<cstdio>
#define maxn 800010
#define le u<<1
#define ri u<<1|1
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long 
ll tr[maxn],la[maxn],add,mit,mt[maxn];
int n,m,usl,usr,zi,maxrange;
void create(int u,int l,int r)
{
	if(l == r) {scanf("%lld",&tr[u]); return;}
	int mid = (l + r) / 2;
	create(le,l,mid); create(ri,mid+1,r);
	tr[u] = tr[le] + tr[ri];
	return;
}
void lazy_add(int u,int l,int r)
{
	if (l>r) return;
	if(usl <= l && r <= usr) la[u] += add;
	else
	{
		if(usl>r || usr<l) return;
		if(u>maxrange) return;
		int mid = (l+r) / 2;
		lazy_add(le,l,mid);
		lazy_add(ri,mid+1,r);
		tr[u] += add * (min(r,usr) - max(l,usl) + 1);
	}
	return;	
}
void recreate(int u,int l,int r)
{
	if(usl>r || usr<l) return;
	int mid = (l + r) / 2;
	create(le,l,mid); create(ri,mid+1,r);
	tr[u] = tr[le] + tr[ri];
	return;
}
ll find(int u,int l,int r)
{
	if(usl>r || usr<l) return 0;
	if (l>r) return 0;
	if(usl <= l && r <= usr) {
		return tr[u] + la[u]*(r-l+1);
	}
	else
	{
		if(u>maxrange) return 0;
		int mid = (l+r) / 2;
		return find(le,l,mid) + find(ri,mid+1,r) + la[u]*(min(r,usr) - max(l,usl) + 1);	
	}
}
int main ()
{
	scanf("%d%d",&n,&m);
	maxrange = n*2-1;
	create(1,1,n);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d",&zi);
		if (zi == 1)
		{
			scanf("%d%d%lld",&usl,&usr,&add);
			lazy_add(1,1,n);
		}
		if(zi == 2)
		{
			scanf("%d%d",&usl,&usr);
			printf("%lld\n",find(1,1,n));
		}
	}
}