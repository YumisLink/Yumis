#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 100010
int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int qwe;
bool check(int y) {
  if (y % 400 == 0) return true;
  if (y % 100 == 0) return false;
  if (y % 4 == 0) return true;
  return false;
}
int main() {
  // freopen("3.in","r",stdin);
  // freopen("3.out","w",stdout);
  scanf("%d", &qwe);
  for (int www = 1; www <= qwe; www++) {
    int n, st, ed;
    int ans = 0;
    scanf("%d", &n);
    scanf("%d%d", &st, &ed);
    int s1 = st / 10000, s2 = st % 10000 / 100, s3 = st % 100;
    int e1 = ed / 10000, e2 = ed % 10000 / 100, e3 = ed % 100;

    int i = s1, j = s2, k = s3;
    for (; i <= e1; i++) {    //年份
      for (; j <= 12; j++) {  //月份
        if (i == e1 && j > e2) {
          break;
        }
        for (; k <= month[j]; k++) {
          // printf("%d y  %d m %d d",i,j,k);
          if (k == 29 && j == 2 && !check(i)) break;
          bool vis[100];
          memset(vis, 0, sizeof(vis));
          if (k % 10 == n % 10) ans++;
          for (int cnt = 1, cot = k; cnt <= 10; cnt++, cot = (cot * j) % 100) {
            while (vis[cot]) {
              cot++;
              cot %= 100;
            }
            if (cot == n) ans++;
            vis[cot] = 1;
          if (i == e1 && j == e2 && k == e3) {
            break;
          }
          }
        }
        k = 1;
      }
      j = 1;
    }
    printf("%d\n", ans);
  }
}