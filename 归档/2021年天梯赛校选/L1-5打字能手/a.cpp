#include <cstdio>
#include <cstring>
int add[27] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
               3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4, 0},
    ans;
int main() {
  char ch[310];
  while (scanf("%s", ch) != EOF) {
    ans++;
    for (int i = 0; i < std::strlen(ch); i++) {
      ans += add[ch[i] - 'a'];
    }
  }
  printf("%d", ans - 1);
}