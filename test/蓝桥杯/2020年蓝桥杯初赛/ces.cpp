#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
class Sstring
{
private:
    char ch[256];
    int leng;

public:
    void scin()
    {
        scanf("%s", ch);
        leng = strlen(ch);
    }
    bool StrCompare(Sstring str)
    {
        if (str.leng != leng)
            return false;
        for (int i = 0; i < leng; i++)
            if (str.ch[i] != ch[i])
                return false;
        return true;
    }
    void StrDelete(int pos, int le)
    {
        for (int i = pos; i < pos + le; i ++)
        {
            ch[i] = ch[i + le];
            ch[i + le] = ' ';
        }
        leng -= le;
    }
    void StrInsert(Sstring insert, int pos)
    {
        for (int i = pos; i < pos + insert.leng; i++)
        {
            for (int j = leng + (i - pos + 1); j > i; j--)
            {
                ch[j] = ch[j - 1];
            }
            ch[i] = insert.ch[i - pos];
        }
    }
    void ConnectStr(Sstring con)
    {
        for (int i = leng; i <= leng + con.leng; i++)
            ch[i] = con.ch[i - leng];
    }
    int Index_bf(Sstring str)
    {
        for (int i = 0; i < leng - str.leng + 1; i++)
        {
            for (int j = 0; j <= str.leng; j++)
            {
                if (ch[i] != str.ch[j])
                {
                    break;
                }
                if (j - 1 == str.leng)
                {
                    return i - j;
                }
            }
        }
        return -1;
    }
    void print()
    {
        for (int i = 0; i < leng; i ++)
            printf("%c",ch[i]);
        puts("");
    }
};

int
main()
{
    Sstring s = new Sstring();
    Sstring a = new Sstring();
    s.scin();
    a.scin();
    printf("%d\n",s.StrCompare(a));
    s.ConnectStr(a);
    s.print();
}