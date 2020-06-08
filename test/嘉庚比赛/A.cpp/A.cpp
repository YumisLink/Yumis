#include<iostream>
using namespace std;
int main ()
{
    long long a,b,c,d;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a >> b >> c >> d;
        long long kk,yy;
        long long ky,yk;
        kk = a/b;
        yy = c/d;
        ky = a % b;
        yk = c % d;

        if (kk > yy) cout << 1 << endl;
        if (kk < yy) cout << -1 << endl;
        if (kk == yy)
        {
            long long k,y;
            k = ky * d;
            y = yk * b;
            if (k > y) cout << 1 << endl;
            else if (k < y) cout << -1 << endl; 
            else cout << 0 << endl;
        }
    }
}