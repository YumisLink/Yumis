#include<cstdio>
int x,y,a,b,sum[1100][1100];
int dir = 0;// 0右边  1下面 2左边 3上面
int add_y[4] = {1,0,-1,0},add_x[4] = {0,1,0,-1};
int main ()
{
    scanf("%d%d%d%d",&x,&y,&a,&b);
    int nx = 1,ny = 0;
    for (int i = 1; i <= x*y ; i ++)
    {
        while(1)
        {
            dir %= 4;
            if(sum[nx + add_x[dir]][ny + add_y[dir]]  > 0)
            {
                dir ++;
                continue;
            }
            if(nx + add_x[dir] > x || ny + add_y[dir] > y)
            {
                dir ++;
                continue;
            }
            if(nx + add_x[dir] <= 0 || ny + add_y[dir] <= 0)
            {
                dir ++;
                continue;
            }
            nx += add_x[dir];
            ny += add_y[dir];
            break;
        }
        sum[nx][ny] = i;
    }
    printf("%d",sum[a][b]);
}