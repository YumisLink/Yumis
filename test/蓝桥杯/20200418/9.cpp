#include<cstdio>
#include<algorithm>
#include<cmath>
#define MAXN 1000*1000 + 1000
int fa[1010],n,m;
double ans;

struct cns
{
    int x,y,h;
}c[1010];

struct poi
{
    int f,t;
    double v;
}p[MAXN];

bool cmp(const poi &a,const poi &b)
{
    return a.v < b.v;
}

inline double way(cns A,cns B)
{
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y)) + (A.h-B.h)*(A.h-B.h);
} 

int find(int a)
{
    if (fa[a] != a)
        return fa[a] = find(fa[a]);
    else 
        return a;
}

int main ()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++) fa[i] = i;
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].h);
    }
    int head = 1;
    for (int i = 1; i <= n;i ++)
        for (int j = i +1; j <= n; j ++)
        {
            p[head].f = i;
            p[head].t = j;
            p[head].v = way(c[i],c[j]); 
            head++;
        }
    head --;

    std::sort(p+1,p+head+1,cmp);

    for (int i = 1; i <= head; i ++)
	{
		int a = find(p[i].f),b = find(p[i].t);
		if (a != b) 
        {
            ans += p[i].v;
            fa[a] = b;
        }
	}

    printf("%.2f",ans);
}