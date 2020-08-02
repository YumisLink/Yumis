#include<cstdio>
#define MAXN 1000100
int T;
int n,q,w,head = 0;
char ch[MAXN];
int pot[MAXN];
int f[MAXN],t[MAXN];
// void put1()
// {
//   for (int i = 0; i < q; i ++)
//   {
//     printf("%d ",pot[i]);
//   }
//   puts("");
// }
int main()
{
  scanf("%d",&T);
  for (int qwe = 1; qwe <= T; qwe ++)
  {
    head = 0;
    scanf("%d\n",&n);
    scanf("%s",ch);
    scanf("%d%d",&q,&w);
    for (int i = 0; i < q; i ++) {pot[i] = 0;}
    for (int i = 1; i <= w ; i ++)
    {
      scanf("%d%d",&f[i],&t[i]);
      pot[f[i]]++;pot[t[i]]++;
    }
    for (int i = 1; i <= w; i ++)
    {
      if(pot[f[i]] > 2 && pot[t[i]] > 2)
      {
        // put1();
        pot[f[i]] --;
        pot[t[i]] --;
        head ++;
          // printf("red %d and %d   beaca %d %d   head : %d\n",f[i],t[i],pot[f[i]],pot[t[i]],head);
        f[i] = -1;
        t[i] = -1;
      }
      if (head == n) head = 0;
    }

    for (int i = 1; i <= w; i ++)
    {
      if(f[i] != -1 || t[i] != -1)
      {
        if(pot[f[i]] > 1 && pot[t[i]] > 1)
        {
          // put1();
          pot[f[i]] --;
          pot[t[i]] --;
          head ++;
          if (head == n) head = 0;
          // printf("red %d and %d   beaca %d %d   head : %d\n",f[i],t[i],pot[f[i]],pot[t[i]],head);
        }
      }
    }
    printf("%c\n",ch[head]);
  }
}