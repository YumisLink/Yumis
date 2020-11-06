#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
char ch[100010];
int first[50];
priority_queue<int> Q;
int main()
{
    scanf("%s", ch);
    int l = strlen(ch);
    long long cnt = 0;
    for (int i = 1; i <= 40; i++)
        first[i] = -1;
    for (int i = 0; i < l; i++)
    {
        int ret = 0;
        first[ch[i] - 'a'] = i;
        for (int j = 0; j < 24; j++)
        {
            if (first[j] != -1)
            {
                Q.push(first[j]);
            }
        }
        Q.push(-1);
        int add = 1;
        int st = Q.top(), ed;
        Q.pop();
        while (!Q.empty())
        {
            int ed = Q.top();
            Q.pop();
            cnt += (st - ed) * add;
            ret += (st - ed) * add;
            add ++;
            st = ed;
        }
        printf("i = %d add le %d\n",i,ret);
    }
    printf("%lld", cnt);
}