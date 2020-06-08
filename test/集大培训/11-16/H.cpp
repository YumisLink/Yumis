
#include <cstdio>
#include<cstring>
#include<cstdlib>
#define max(a,b) ((a)>(b)?(a):(b))
#define mod 20121014
#define inf 0x3f3f3f3f
using namespace std;
int a[10];
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        memset(a,0,sizeof(a));
        int sum = 0;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        int ans = 0;
        if(n <= 3 && n >= 0)
            ans = 1024;
        else if(n == 4)
        {
            bool flag = 0;
            for(int i = 1; i <= n ; i ++)
            {
                for(int j = i + 1; j <= n; j ++)
                {
                    for(int k = j + 1; k <= n; k ++)
                    {
                        if((a[i] + a[j] + a[k]) % 1024 == 0)
                        {
                            ans = 1024;
                            flag = 1;
                        }
                    }
                }
            }
            if(!flag)
            {
                int minn = inf;
                for(int i = 1; i <= n; i ++)
                {
                    for(int j = i + 1; j <= n; j ++)
                    {
                        int tmp = a[i] + a[j];
                        while(tmp > 1024)
                            tmp -= 1024;
                        ans = max (tmp,ans);
                    }
                }
            }
        }
        else if(n == 5)
        {
            bool flag = 0;
            for(int i = 1; i <= n; i ++)
            {
                for(int j = i + 1; j <= n; j ++)
                {
                    if((sum - a[i] - a[j]) % 1024 == 0)
                    {
                        flag = 1;
                        int tmp = a[i] + a[j];
                        while(tmp > 1024)
                            tmp -= 1024;
                        ans = max(tmp,ans);
                    }
                }
            }
            if(!flag)
                ans = 0;
        }
        printf("%d\n",ans);
    }
    return 0;
}