#include <cstdio>
#include <string>
#define MAXN 100010
using namespace std;
int qwe;
int main() {
  scanf("%d", &qwe);
  for (int www = 1; www <= qwe; www++) {
    int a,b;
    char s[100010];
    scanf("%d%d",&a,&b);
    scanf("%s",s);
    if (b == 0){
      puts("YES");
      continue;
    }
    if (b*2+1 > a){
      puts("NO");
      continue;
    }
    for (int i = 0; i < a; i ++)
    {
      if (s[i] == s[a-1-i]){
        b --;
      }
      else
        break;
      if (b == 0)
        break;
    }
    if (b == 0){
      puts("YES");
      continue;
    }
    else{
      puts("NO");
      continue;
    }

  }
}
