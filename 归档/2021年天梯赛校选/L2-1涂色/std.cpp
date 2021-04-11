#include <cstdio>
using namespace std;
int n;
int a[32][32];
void dfs(int x, int y) {
	if (x >= 0 && x <= n + 1 && y >= 0 && y <= n + 1) {
		if (a[x][y] == 1 || a[x][y] == 3) return;
		else {
			a[x][y] = 3;
			dfs(x + 1, y); dfs(x - 1, y);
			dfs(x, y + 1); dfs(x, y - 1);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	dfs(0, 0);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i][j] == 3) a[i][j] = 0;
			else if (a[i][j] == 0) a[i][j] = 2;
	for (int i = 1; i <= n; ++i, printf("\n"))
		for (int j = 1; j <= n; printf("%d ", a[i][j]), ++j);
	return 0;
}