#include <cstdio>
#include <queue>
using namespace std;
int qwe;
int main() {
  // freopen("4.in", "r", stdin);
  // freopen("4.out","w",stdout);
  scanf("%d", &qwe);
  for (int www = 1; www <= qwe; www++) {
    int lef[300] = {0}, rig[300] = {0}, s[300] = {0}, n;
    scanf("%d", &n);
    queue<pair<int, int> > D, T;
    queue<int>Q;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &s[i]);
      D.push(make_pair(s[i], i));
    }
    int top = n;
    while (D.size() > 1) {
      T = D;
      while (!D.empty()) D.pop();
      while (T.size() > 1) {
        int a, b;
        a = T.front().first;
        b = T.front().second;
        T.pop();
        D.push(make_pair(a + T.front().first, ++top));
        s[top] = a + T.front().first;
        lef[top] = b, rig[top] = T.front().second;
        T.pop();
      }
      if (T.size() == 1) D.push(T.front());
    }
    Q.push(D.front().second);
    while (!Q.empty()) {
      int k = Q.front();
      Q.pop();
      if (k == 0) continue;
      printf("%d ", s[k]);
      Q.push(lef[k]);
      Q.push(rig[k]);
    }
  }
}