#include<cstdio>
#include<cmath>
using namespace std;
int n;
int main ()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i ++)
    {
        long long ax,ay,bx,by,cx,cy;
        scanf("%lld%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&cx,&cy);
        if (ax == cx && ay == cy) {puts("0");continue;}
        if (bx == cx && by == cy) {puts("0");continue;}
        double ab,ac,bc;
        ab = sqrt(double(ax-bx)*double(ax-bx) + double(ay-by)*double(ay-by));
        bc = sqrt(double(bx-cx)*double(bx-cx) + double(by-cy)*double(by-cy));
        ac = sqrt(double(ax-cx)*double(ax-cx) + double(ay-cy)*double(ay-cy));
        // printf("%.3lf  %.3lf  %.3lf\n",ab,bc,ac);
        double x = (bc*bc - ac*ac + ab*ab) / (2*ab);
        double y = sqrt((ac*ac) - (x*x));
        x = abs(x);  y = abs(y);
        // printf("%.3lf  %.3lf\n",x,y);
        printf("%.2lf\n",x*y);
    }
}