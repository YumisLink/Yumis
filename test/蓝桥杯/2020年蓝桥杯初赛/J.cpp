#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a;
int ch[27];
int ret()
{
    int r = 0;
    int add = 0;
    int i;
    for (i = 26; i >= 1; i--)
        if (ch[i])
            break;
    for (; i >= 1; i--)
    {
        r += add * ch[i];
        add += ch[i];
    }
    return r;
}
int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    ch[1] = 1;
    int add = 0, head = 1, flag = 0;
    for (; ans < n;)
    {
        head++;
        if (head == 27)
        {
            head = 1;
            flag++;
        }
        else
            add++;
        ch[head]++;
        ans += add;
    }

    int sub, last;
    if (!flag)
    {
        sub = head;
        head = 1;
    }
    else
    {
        sub = 26;
        head++;
    }

    for (; ans != n;)
    {
        if (!flag)
        {
            ans--;
            ch[sub]--;
            sub--;
            ch[head]++;
            head++;
        }
        else
        {
            if (ch[sub] != 0)
            {
                ch[sub]--;
                ch[head]++;
            }
            else
            {
                sub--;
                ch[sub]--;
                ch[head]++;
            }
            if (ret() < n)
            {
                ch[sub]++;
                sub--;
                ch[sub]--;
            }
            ans = ret();
            head++;
            if (head >= sub)
            {
                head = 1;
                flag++;
            }
        }
    }
    for (int i = 26; i >= 1; i--)
    {
        while (ch[i] > 0)
        {
            printf("%c", i + 'a' - 1);
            ch[i]--;
        }
    }
}
