#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int a[10010];
int main() {
  int qwe;
  scanf("%d", &qwe);
  for (int qaq = 1; qaq <= qwe; qaq++) {
    queue<pair<int, int> > v;
    int n;
    scanf("%d", &n);
    n *= 2;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    // for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    // puts("***");
    int flag = 0;
    int now = a[n];
    // printf("now = %d\n", now);
    int j;
    for (int i = n - 1; i >= 1; i--) {
      // printf("*%d*%d\n", i, a[i]);
      if (i == 1 && flag == 0) {
        flag = a[1];
        break;
      }
      if (a[i] <= 0) continue;
      for (j = i - 1; j >= 1; j--) {
        // if (j == 0) puts("??");
        if (now == a[i] + a[j]) {
          j--;
          break;
        }
      }
      j++;
      if (now != a[i] + a[j]) {
        if (!flag && now != a[n]) {
          flag = now;
          now = 0;
          while (now <= 0 && i > 0) {
            now = a[i];
            i--;
          }
          continue;
        } else {
          printf("NO\n");
          flag = -1;
          // puts("**************");
          break;
        }
      } else {
        // printf("j = %d   %d+%d = %d* nowflag = %d**\n", j, a[j], a[i], now,
        //  flag);
        now = a[i];
        v.push(make_pair(a[j], a[i]));
        // puts("add success");
        a[i] = -0x3f3f3f3f;
        a[j] = -0x3f3f3f3f;
      }
    }
    if (flag == -1) continue;
    printf("YES\n");
    printf("%d\n", flag + a[n]);
    printf("%d %d\n", flag, a[n]);
    while (!v.empty()) {
      printf("%d %d\n", v.front().first, v.front().second);
      v.pop();
    }
    // puts("**************");
  }
}