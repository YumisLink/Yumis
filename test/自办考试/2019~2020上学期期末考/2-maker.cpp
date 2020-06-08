#include<bits/stdc++.h>
#define MAXN 100010
#define LL long long
#define random(a,b) (((LL)rand()*(LL)rand()*(LL)rand()) % ((b)-(a)+1) + (a)) 
using namespace std;

#define text1 "Yumis20.in"
#define text2 srand(31)
//n
#define text3 random(100000,100000)
//at
#define text4 random(1000000000,100000000000000)
//c
#define text5 random(1000000000,1000000000000000)
//time
#define text6 random(100000,350020)
#define text7 "Yumis20.out"


map<LL ,LL>M;
LL fa[MAXN],ne[MAXN],head,t[MAXN],n,now,at,fr,a,b,c,name[MAXN],print[MAXN],phead,ans;
LL outc()
{
    LL k = text5;
    while (M[k])
        k = text5;
    return k;
}
void del(LL ti)
{
    now = b;
    if (t[fr] == 0) return;
    while(ti)
    {
        if (t[fr] == 0) break;
        if (t[fr] <= ti)
        {
            LL root = fr;
            ti -= t[root];
            fr = ne[root];
            phead ++;
            print[phead] = name[root];
            name[root] = t[root] = ne[root] = 0;
            fa[fr] = 0;
        }
        else 
        {
            t[fr] -= ti;
            return ;
        }
    }
}
void upper(LL root)  //将链表中的root提升到头
{
    ne[fa[root]] = ne[root];
    fa[ne[root]] = fa[root];
    fa[root] = 0;
    ne[root] = fr;
    fr = root;
}

int main ()
{
    freopen(text1,"w",stdout);
    text2;
    n = text3;
    at = text4;
    printf("%lld %lld\n",n,at);
    now = 0;
    for (int i = 1 ; i <= n; i ++)
    {
        int cot = 0;
        if (i <= 500) a = 1;
        else a = random(1,2);
        b += random(1,at/n + at/2/n);
        if (a == 2)
        {
            c = random(1,head);
            while(t[c] == 0)
            {
                c = random(1,head);
                cot ++;
                if (cot == head){a = 1;break;}
            }
            c = name[c];
        }
        else 
            c = outc();
        if (cot == head) c = outc();
        printf("%lld %lld %lld ",a,b,c);
        if (a == 1)
        {
            del(b-now);
            LL time;
            time = text6;
            printf("%lld\n",time);
            head ++;
            t[head] = time;
            ans += time;
            M[c] = head;
            fa[fr] = head;
            ne[head] = fr;
            fr = head;
            name[head] = c;
        }
        if (a == 2)
        {
            puts("");
            del(b-now);
            upper(M[c]);
        }
    }
    del(at-now);
    fclose(stdout);
    freopen(text7,"w",stdout);
    for (int i = 1 ; i <= phead; i ++)
        printf("%lld\n",print[i]);
    fclose(stdout);
}