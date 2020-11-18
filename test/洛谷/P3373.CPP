#include <cstdio>
#include <cstring>
#define LL long long
#define UPDATE d[root] = (d[root << 1] + d[root << 1 | 1]) % MOD
#define max(a, b) ((a) > (b) ? (a) : (b))
#define MAXN 500100
LL d[MAXN * 2], lazy_add[MAXN * 2], lazy_mult[MAXN * 2];
LL bigg;
LL n, m, MOD;
LL create(LL lef, LL rig, LL root)
{
	bigg = max(bigg, root);
	lazy_mult[root] = 1;
	if (lef == rig)
	{
		scanf("%lld", &d[root]);
		return d[root];
	}
	LL mid = (lef + rig) / 2;
	d[root] = (create(lef, mid, root << 1) + create(mid + 1, rig, root << 1 | 1)) % MOD;
	return d[root];
}
void update(LL lef, LL rig, LL root)
{
	if (lef == rig)
		return;
	LL mid = (lef + rig) / 2;
	d[root << 1] = (lazy_mult[root] * d[root << 1] + ((mid - lef + 1) * lazy_add[root]) % MOD) % MOD;
	d[root << 1 | 1] = (lazy_mult[root] * d[root << 1 | 1] + ((rig - mid) * lazy_add[root]) % MOD) % MOD;

	lazy_mult[root << 1] = (lazy_mult[root << 1] * lazy_mult[root]) % MOD;
	lazy_mult[root << 1 | 1] = (lazy_mult[root << 1 | 1] * lazy_mult[root]) % MOD;

	lazy_add[root << 1] = (lazy_add[root << 1] * lazy_mult[root] + lazy_add[root]) % MOD;
	lazy_add[root << 1 | 1] = (lazy_add[root << 1 | 1] * lazy_mult[root] + lazy_add[root]) % MOD;

	lazy_add[root] = 0;
	lazy_mult[root] = 1;
	d[root] = (d[root << 1] + d[root << 1 | 1]) % MOD;
}
void add(LL lef, LL rig, LL root, LL mlef, LL mrig, LL addd)
{
	if (mlef <= lef && rig <= mrig)
	{
		lazy_add[root] = (lazy_add[root] + addd) % MOD;
		d[root] = (d[root] +  addd * (rig - lef + 1)) % MOD;
		return;
	}
	update(lef, rig, root);
	UPDATE;
	LL mid = (lef + rig) / 2;
	if (mlef <= mid)
		add(lef, mid, root << 1, mlef, mrig, addd);
	if (mid < mrig)
		add(mid + 1, rig, root << 1 | 1, mlef, mrig, addd);
	UPDATE;
}
void mult(LL lef, LL rig, LL root, LL mlef, LL mrig, LL multt)
{
	if (mlef <= lef && rig <= mrig)
	{
		lazy_add[root] = (lazy_add[root] * multt) % MOD;
		lazy_mult[root] = (lazy_mult[root] * multt) % MOD;
		d[root] = (d[root] * multt) % MOD;
		return;
	}
	update(lef, rig, root);
	UPDATE;
	LL mid = (lef + rig) / 2;
	if (mlef <= mid)
		mult(lef, mid, root << 1, mlef, mrig, multt);
	if (mid < mrig)
		mult(mid + 1, rig, root << 1 | 1, mlef, mrig, multt);
	UPDATE;
}
LL find(LL lef, LL rig, LL root, LL mlef, LL mrig)
{
	if (mlef <= lef && rig <= mrig)
	{
		return d[root];
	}
	update(lef, rig, root);
	LL val = 0;
	LL mid = (rig + lef) / 2;
	if (mlef <= mid)
		val = (val + find(lef, mid, root << 1, mlef, mrig)) % MOD;
	if (mid < mrig)
		val = (val + find(mid + 1, rig, root << 1 | 1, mlef, mrig)) % MOD;
	return val;
}
void search(LL lef, LL rig, LL root)
{
	if (lef == rig)
	{
		printf("%lld ", d[root]);
		return;
	}
	update(lef, rig, root);
	LL mid = (lef + rig) / 2;
	search(lef, mid, root << 1);
	search(mid + 1, rig, root << 1 | 1);
}
int main()
{
	memset(d, 0, sizeof(d));
	scanf("%lld%lld%lld", &n, &m, &MOD);
	create(1, n, 1);

	for (LL i = 1; i <= m; i++)
	{
		LL k = 1;
		scanf("%lld", &k);
		if (k == 1)
		{
			LL x, y, z;
			scanf("%lld%lld%lld", &x, &y, &z);
			mult(1, n, 1, x, y, z);
		}
		if (k == 2)
		{
			LL x, y, z;
			scanf("%lld%lld%lld", &x, &y, &z);
			add(1, n, 1, x, y, z);
		}
		if (k == 3)
		{
			LL x, y;
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", find(1, n, 1, x, y));
		}
	}
}