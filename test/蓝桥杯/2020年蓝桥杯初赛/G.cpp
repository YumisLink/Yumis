#include <cstdio>
int k[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n1[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool nnn(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return 1;
    return 0;

}

bool case1(int hw)
{
    char ch[9];
    for (int i = 1; i <= 8; i++)
    {
        ch[i] = hw % 10;
        hw /= 10;
    }
    for (int i = 1; i <= 4; i++)
    {
        if (ch[i] != ch[9 - i])
            return 0;
    }
    return 1;
}
bool secase(int hw)
{
    char ch[9];
    for (int i = 1; i <= 8; i++)
    {
        ch[i] = hw % 10;
        hw /= 10;
    }
    if (ch[1] == ch[3] && ch[2] == ch[4])
        return 1;
    return 0;
}
int main()
{
    int n;
    int flag = 1;
    scanf("%d", &n);
    int y, m, d;
    y = n / 10000;
    m = n / 100 % 100;
    d = n % 100;
    d++;
    int day;
    if (nnn(y))
    {
        day = n1[m];
    }
    else
    {
        day = k[m];
    }
    if (d > day)
    {
        d = 1;
        m++;
        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
    for (; y <= 9999; y++)
    {
        bool nn = nnn(y);
        for (; m <= 12; m++)
        {
            int s;
            if (nn)
                s = n1[m];
            else
                s = k[m];
            for (; d <= s; d++)
            {
                if (case1(y * 10000 + m * 100 + d))
                {
                    if (flag)
                    {
                        printf("%d\n", y * 10000 + m * 100 + d);
                        flag = 0;
                    }
                    if (secase(y * 10000 + m * 100 + d))
                    {
                        printf("%d\n", y * 10000 + m * 100 + d);
                        return 0;
                    }
                }
            }
            d = 1;
        }
        m = 1;
    }
}