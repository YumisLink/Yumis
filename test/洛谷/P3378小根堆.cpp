#include<cstdio>
#define MAXN 1000010
int a[MAXN],n,head;
void swap(int &x,int &y){int t = x; x = y; y = t;}
void insert(int x)
{
    a[++head] = x;
    int now = head;
    while(now > 1)
    {
        int k = now >> 1;
        if (a[now] < a[k])
            swap(a[now],a[k]);
        else
            break;
        now = k;
    }
    return ;
}
void del()
{
    int now = 1;
    swap(a[now],a[head]);
    a[head] = 0;
    head--;
    while((now<<1) <= head)
    {
        int k = now << 1;
        if (k + 1 <= head  &&  a[k+1] < a[k]) k ++;
        if (a[now] > a[k]) swap(a[k],a[now]);
        else break;
        now = k;
    }
}
int head()
{
    return a[1];
}
int main ()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++)
    {
        int g,b;
        scanf("%d",&g);
        if (g == 1)
        {
            scanf("%d",&b);
            insert(b);
        }
        if (g == 2)
            printf("%d\n",a[1]);
        if (g == 3)
            del();
    }
    return 0;
}