#include<cstring>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int n;
int main ()
{
    cin >> n;
    for (int i = 1;i <= n; i ++)
    {
        char str[500];
        cin >> str;
        int kk = strlen(str);
        int tag1=0,tag2=0,tag3=0,tag4=0;
        if (kk < 8 || kk >16) {puts("NO");continue;}
        for (int i = 0; i < kk; i++)
        {
            // cout << str << ' ' << i << endl;
            char ch = str[i];
            if (ch >= '0' && ch <= '9') tag1 = 1;
            if (ch >= 'A' && ch <= 'Z') tag2 = 1;
            if (ch >= 'a' && ch <= 'z') tag3 = 1;
            if (ch == '~' || ch == '!' || ch == '@' || ch == '$' || ch == '%' || ch == '^') tag4 = 1;
        }
        if (tag1 + tag2 + tag3 + tag4 >= 3) puts("YES");
        else    puts("NO");

    }
}