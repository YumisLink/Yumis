#include<cstdio>
#include<cstring>
char add(char ch)
{
    if (ch <= 'w') 
        return ch+3;
    if (ch == 'x')
        return 'a';
    if (ch == 'y')
        return 'b';
    return 'c';
}
char ch[110];
int main ()
{
    scanf("%s",ch);
    int l = strlen(ch);
    for (int i = 0; i < l; i ++)
        printf("%c",add(ch[i]));
}
