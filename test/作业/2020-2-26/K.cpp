#include <cstdio>
int main() 
{  
    int n,m,mx1=55,mx2=55,mi1=66,mi2=66,k[100][100];
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j++)
            scanf("%d",&k[i][j]);
    k[mi1][mi2] = 0x3f3f3f;
    k[mx1][mx2] = 0x3f3f3f * -1;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j++)
        {
            if (k[mi1][mi2] > k[i][j])
            {
                mi1 = i;
                mi2 = j;
            }
            if (k[mx1][mx2] < k[i][j])
            {
                mx1 = i;
                mx2 = j;
            }
        }
    // printf("max=%d row=%d col=%d\n",k[mx1][mx2],mx1,mx2);
    // printf("min=%d row=%d col=%d\n",k[mi1][mi2],mi1,mi2);
     printf("%d %d %d\n",k[mx1][mx2],mx1,mx2);
     printf("%d %d %d\n",k[mi1][mi2],mi1,mi2);
}