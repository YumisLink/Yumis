#include <cstdio>
int n,ans;
char ch;
float k;
int main()
{
    bool flag = 0;
    scanf("%d%d",&ans,&n);
    for (int i = 1; i <= n;i  ++)
    {
        int q;
        scanf("%d",&q);
        if (flag == 0)
        {
            if (ans == q)
            {
                if (i < 3)
                    puts("Lucky You!");
                else 
                    puts("Good Guess!");
            }
            else if (i >= 4)
                    puts("Game Over"),flag = 1;
                else if (q < ans)
                        puts("Too small");
                    else 
                        puts("Too big");
        }

    }
}