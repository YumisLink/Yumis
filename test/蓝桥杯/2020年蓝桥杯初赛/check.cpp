#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int ch[27];
int ret()
{
    int r = 0;
    int add = 0;
    int i;
    for (i = 26; i >= 1; i --)
        if (ch[i])
            break;
    for (; i >= 1; i --)
    {
        r += add * ch[i];
        add += ch[i];
    }
    return r;
}
int main()
{
    char ss[10000];
    scanf("%s",ss);
    int l = std::strlen(ss);
    for (int i = 0 ; i < l; i ++)
        ch[ss[i]-'a' + 1] ++;
    printf("\n%d",ret());
}