#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s;
int kkk[10000];
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        kkk[s[i]]++;
    int all;
    kkk['G'] += kkk['g'];
    kkk['P'] += kkk['p'];
    kkk['L'] += kkk['l'];
    kkk['T'] += kkk['t'];
    all = kkk['G'] + kkk['P'] + kkk['L'] + kkk['T'];
    while (all)
    {
        if (kkk['G'])
        {
            printf("G");
            kkk['G']--;
        }
        if (kkk['P'])
        {
            printf("P");
            kkk['P']--;
        }
        if (kkk['L'])
        {
            printf("L");
            kkk['L']--;
        }
        if (kkk['T'])
        {
            printf("T");
            kkk['T']--;
        }
        all = kkk['G'] + kkk['P'] + kkk['L'] + kkk['T'];
    }
}