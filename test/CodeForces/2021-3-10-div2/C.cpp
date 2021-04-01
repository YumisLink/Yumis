#include <algorithm>
#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
#define get(a, b) sqrt(a* a + b * b)
#define eps 0.0000001
#define cm(a, b) (a > b - eps && a < b + eps)
#define MAXN 100010
using namespace std;
int qwe;
int main() {
  scanf("%d", &qwe);
  for (int www = 1; www <= qwe; www++) {
    int n;
    vector<double> kg, ky;
    scanf("%d", &n);
    for (int i = 1; i <= n * 2; i++) {
      double a, b;
      scanf("%lf%lf", &a, &b);
      if (cm(a, 0))
        kg.push_back(abs(b));
      else
        ky.push_back(abs(a));
    }
    sort(kg.begin(),kg.end());
    sort(ky.begin(),ky.end());
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans += get(kg[i], ky[i]);
    }
    printf("%.15lf\n",ans);
  }
}