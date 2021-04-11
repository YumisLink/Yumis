#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#define MAXN 110
#define ll long long
using namespace std;
int qwe;
int place[MAXN];
int playAt[MAXN];
int now;
nint main() {
  freopen("a.in", "r", stdin);
  scanf("%d", &qwe);
  while (qwe--) {
    memset(playAt, 0, sizeof(playAt));
    memset(place, 0, sizeof(place));
    now = 1;
    int n, m, k, at;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1, q; i <= k; i++) {
      scanf("%d", &q);
      if (i > m) {
        at = playAt[now];
        place[at] = 0;
      }else{
        at = 0;
      }
      // printf("p : %d go %d\n",now,q);
      for (int j = 1; j <= q; j++) {
        at++;
        if (at > n) at %= n;
        while (place[at] != 0) {
          at++;
          if (at > n) at %= n;
        }
      }
      playAt[now] = at;
      place[at] = 1;
      now++;
      if (now == 5) now = 1;
    }
    for (int i = 1; i <= m; i++) printf("%d\n", playAt[i]);
  }
}