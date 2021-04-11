#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 100010
char s1[1010],s2[1010];
int n, a[MAXN];
int main() {
  scanf("%s%s", s1, s2);
  // printf("%s%s",s1.c_str(), s2.c_str());
  int l1 = strlen(s1), l2 = strlen(s2);
  int find = 0, i = 0;
  for (;;) {
    if (i > l2 || find > l1) break;
    if (s2[i] == s1[find]) {
      find++;
      i++;
    } else {
      find++;
    }
  }
  if (i > l2)
    puts("Yes");
  else
    puts("No");
}