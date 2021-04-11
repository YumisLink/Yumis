#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
#define MAXN 100010
int n, a[MAXN];
bool check(char c) {
  if (c == 'A' || c == 'a') return true;
  if (c == 'E' || c == 'e') return true;
  if (c == 'I' || c == 'i') return true;
  if (c == 'O' || c == 'o') return true;
  if (c == 'U' || c == 'u') return true;
  if (c == 'V' || c == 'v') return true;
  return false;
}
int main() {
  freopen("0.in","r",stdin);
  freopen("0.out","w",stdout);
  scanf("%d",&n);
  for (int i = 1; i <= n; i++) {
    char s[100];
    bool flag = false;
    scanf("%s",&s);
    int ss = strlen(s);
    // printf("%s\n",s.c_str());
    for (int i = 0; i <= ss; i++) {
      if (check(s[i])) {
        flag = true;
        puts("NO");
        break;
      }
    }
    if (!flag) puts("YES");
  }
}
      7
   4       3
 2   2   2 
1 1 1 1 1 1 1
7 4 3 2 2 2 1 1 1 1 1 1 1