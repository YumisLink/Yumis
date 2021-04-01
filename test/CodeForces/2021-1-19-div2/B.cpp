#include <algorithm>
#include <cstdio>
#include <vector>
#define MAXN 100010
using namespace std;
int qwe, n;
bool zs[1000100];
vector<int> V;
int main() {
  for (int i = 2; i <= 1000000; i++) {
    if (!zs[i]) {
      V.push_back(i);
      for (int j = i; j <= 1000000; j += i) {
        zs[j] = true;
      }
    }
  }
  scanf("%d", &qwe);
  for (int www = 1; www <= qwe; www++) {
    scanf("%d", &n);
    int a = lower_bound(V.begin(), V.end(), 1 + n) - V.begin();
    int b = lower_bound(V.begin(), V.end(), V[a] + n) - V.begin();
    printf("%d\n", V[a] * V[b]);
  }
}