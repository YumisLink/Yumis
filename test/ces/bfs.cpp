#include <cmath>
#include <cstdio>
#include <utility>
#define VAL 100010
typedef long long ll;
using namespace std;
int n;
pair<ll, ll> f[VAL], offset[VAL];
char op[VAL];

void set(char c, pair<ll, ll>& now) {
  switch (c) {
    case 'U':
      now.second += 1;
      break;
    case 'D':
      now.second -= 1;
      break;
    case 'R':
      now.first += 1;
      break;
    case 'L':
      now.first -= 1;
      break;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    ll cmdC, cyc;
    scanf("%d %d", &cmdC, &cyc);
    pair<ll, ll> now = make_pair(0, 0);
    char t[cmdC + 1];
    scanf("%s", t);
    for (int i = 0; i < cmdC; i++) {
      set(t[i], now);
      f[i] = now;
      op[i] = t[i];
    }
    pair<ll, ll> nxt = f[cmdC - 1];
    for (int i = 0; i < cmdC; i++) {
      set(op[i], nxt);
      offset[i] = make_pair(nxt.first - f[i].first, nxt.second - f[i].second);
    }
    ll max = 0;
    for (int i = 0; i < cmdC; i++) {
      ll x = f[i].first + offset[i].first * (cyc - 1);
      ll y = f[i].second + offset[i].second * (cyc - 1);
      ll nowl = abs(x) + abs(y);
      if (nowl > max) {
        max = nowl;
      }
    }

    printf("%lld\n", max);
  }

  return 0;
}