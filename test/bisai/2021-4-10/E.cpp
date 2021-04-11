#include <cstdio>
#define MAXN 100010
#include <queue>
#include <vector>
using namespace std;
int n, a[MAXN],q,w;
int vis[MAXN], dis[MAXN];
vector<int> V[MAXN];
queue<int> Q;
void cin(int a, int b) {
  V[a].push_back(b);
  V[b].push_back(a);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &q, &w);
    cin(q, w);
  }
  scanf("%d%d", &q, &w);
  Q.push(q);
  vis[q] = 1;
  while (!Q.empty()) {
    int k = Q.front();
    Q.pop();
    for (int i = 0; i < V[k].size(); i++) {
      if (!vis[V[k][i]]) {
        dis[V[k][i]] = dis[k] + 1;
        vis[V[k][i]] = true;
        Q.push(V[k][i]);
      }
    }
  }
  if (dis[w] % 2 == 0) printf("No");
  else printf("Yes");
  // for (int i = 1; i <= n; i ++){
  //   printf("%d ",dis[i]);
  // }
}