#include <cstdio>
#include <string>
#include <iostream>
#define MAXN 100010
using namespace std;
int n, a[MAXN], flag;
string s, ans;
int main()
{
    cin >> s;
    if ((s[0] - '0') * 10 + (s[1] - '0') > 12 && (s[0] - '0') * 10 + (s[1] - '0') < 24)
    {
        n = (s[0] - '0') * 10 + (s[1] - '0') - 12;
        flag = 1;
    }
    for (int i = 1; i <= n; i++)
        ans += "Dang";
    if ((s[3] - '0') * 10 + (s[4] - '0') > 0)
        ans += "Dang";
    if (flag)
        cout << ans;
    else
        cout << "Only " << s << ".  Too early to Dang.";
}