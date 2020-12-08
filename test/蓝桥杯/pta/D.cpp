#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#define MAXN 100010
using namespace std;
int n, m, a[MAXN];
map<string, bool> M;
vector<string> V;
string s;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            cin >> s;
            if (m != 1)
                M[s] = true;
        }
    }
    bool flag = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        if (!M[s])
        {
            V.push_back(s);
            M[s] = 1;
            flag = 0;
        }
    }
    if (flag)
        printf("No one is handsome");
    else
    {
        for (int i = 0; i < V.size() - 1; i++)
            cout << V[i] << " ";
        cout << V[V.size() - 1];
    }
}