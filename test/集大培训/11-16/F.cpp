#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    while(1)
    {
        char lch;
        map<string,int>M;
        int ans = 0;
        while (1)
        {
            string str,sb = "";
            M[sb] = 1;
            while (1)
            {
                lch = getchar();
                if (lch == '#') return 0;
                if (lch == 10) break;
                if (lch != ' ')
                    str += lch;
                else 
                    break;
            }
            if (M[str] == 0) {ans ++;M[str] ++;}
            if (lch == 10) break;
        }
        printf("%d\n",ans);
    }
}