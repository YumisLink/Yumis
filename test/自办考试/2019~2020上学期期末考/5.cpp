#include<cstdio>
#define MAXN 500010
int left[MAXN],right[MAXN],sum[MAXN],head = 1,n;
void create(int root,int k)
{
    if (k < sum[root])
    {
        if (left[root] == 0)
        {
            left[root] = ++head;
            sum[head] = k;
        }
        else create(left[root],k);
    }
    else 
    {
        if (right[root] == 0)
        {
            right[root] = ++head;
            sum[head] = k;
        }
        else create(right[root],k);
    }
}
void frfind(int root){if (root == 0) return;printf("%d ",sum[root]);frfind(left[root]);frfind(right[root]);}
void midfind(int root){if (root == 0) return;midfind(left[root]);printf("%d ",sum[root]);midfind(right[root]);}
void edfind(int root){if (root == 0) return;edfind(left[root]);edfind(right[root]);printf("%d ",sum[root]);}
int main ()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        int q;
        scanf("%d",&q);
        if (head == 1) {sum[head] = q;head++;}
        else create(1,q);
    }
    frfind(1);puts("");
    midfind(1);puts("");
    edfind(1);
}