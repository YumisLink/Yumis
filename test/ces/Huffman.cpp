#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
#define MAXN 100010
using namespace std;
priority_queue<pair<int, int> > Q;
int spa[MAXN], lef[MAXN], rig[MAXN], fat[MAXN];
int c[30], ans, head;
string a;
void midfind(int root, string st)
{
    if (spa[root] == '#')
    {
        midfind(lef[root], st + '0');
        midfind(rig[root], st + '1');
    }
    else
        printf("%c %s\n", spa[root], st.c_str());
}
int main()
{
    cin >> a;
    for (int i = 0; i < a.length(); i++)
        c[a[i] - 'A']++;
    for (int i = 'A'; i <= 'Z'; i++)
        if (c[i - 'A'])
            Q.push(make_pair(-c[i - 'A'], i));
    while (Q.size() > 1)
    {
        int a1 = -Q.top().first;
        int c1 = Q.top().second;
        Q.pop();
        int a2 = -Q.top().first;
        int c2 = Q.top().second;
        Q.pop();
        ans += a1 + a2;
        int p1, p2, p3;
        if (c1 > 1000)
            p1 = c1 - 1000;
        else
            p1 = ++head, spa[p1] = c1;
        if (c2 > 1000)
            p2 = c2 - 1000;
        else
            p2 = ++head, spa[p2] = c2;
        p3 = ++head;
        lef[p3] = p1;
        rig[p3] = p2;
        spa[p3] = '#';
        Q.push(make_pair(-(a1 + a2), 1000 + p3));
    }
    printf("%d\n", ans);
    midfind(head, "");
}