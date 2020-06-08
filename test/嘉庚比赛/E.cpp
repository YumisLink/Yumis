#include<cstdio>
#include<iostream>
#define MAXN 1000010
using namespace std;
long long k[MAXN],n,asd;
int main ()
{
    cin >> asd;
    for (int i = 1; i <= asd; i ++)
        cin >> k[i];
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (a == 1)
            k[b] += c;
        if (a == 2)
        {
            k[b] -= c;
            if (k[b] < 0) 
                k[b] = 0;
        }
        if (a == 3)
        {
            int qwe = k[b];
            k[b] = k[c];
            k[c] = qwe;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= asd; i ++)
        ans += k[i];
    cout << ans << endl;
    return 0;
}