#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 100010
#define PI 3.141592653589793
#define calc(aa, bb, cc) (cross((bb) - (aa), (cc) - (bb)))
#define eps 1e-12

struct Vector2
{
    double x, y;
} p[MAXN << 2], stack[MAXN << 2];

double cross(Vector2 A, Vector2 B) { return A.x * B.y - A.y * B.x; }
double abs(Vector2 A) { return sqrt(A.x * A.x + A.y * A.y); }
Vector2 operator-(Vector2 A, Vector2 B) { return (Vector2){A.x - B.x, A.y - B.y}; }
Vector2 operator+(Vector2 A, Vector2 B) { return (Vector2){A.x + B.x, A.y + B.y}; }
bool operator<(Vector2 A, Vector2 B) { return A.x == B.x ? A.y < B.y : A.x < B.x; }
Vector2 rotate(Vector2 A, double agl) { return (Vector2){A.x * cos(agl) - A.y * sin(agl), A.x * sin(agl) + A.y * cos(agl)}; }
int n, cnt = 0;
double a, b, r, x, y, t;

int main()
{
    scanf("%d%lf%lf%lf", &n, &b, &a, &r);
    a /= 2.0, b /= 2.0; // 取得半长和半宽
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf%lf%lf", &x, &y, &t);
        x += eps, y += eps, t += eps;                      // 扰动，避免出现除0或者NaN
        Vector2 add = (Vector2){x, y};                       // 中心
        p[++cnt] = rotate((Vector2){a - r, b - r}, t) + add; // 先旋转再加中心
        p[++cnt] = rotate((Vector2){r - a, b - r}, t) + add;
        p[++cnt] = rotate((Vector2){r - a, r - b}, t) + add;
        p[++cnt] = rotate((Vector2){a - r, r - b}, t) + add;
    }
    std::sort(p + 1, p + cnt + 1); // x-y 排序
    int T = 0;
    for (int i = 1; i <= cnt; i++)
    { // 下凸壳
        while (T > 1 && calc(stack[T - 1], stack[T], p[i]) <= 0)
            T--;
        stack[++T] = p[i];
    }
    int tmp = T;
    for (int i = cnt - 1; i; i--)
    { // 上凸壳
        while (T > tmp && calc(stack[T - 1], stack[T], p[i]) <= 0)
            T--;
        stack[++T] = p[i];
    }
    double ans = 2 * PI * r; // 加上一周
    for (int i = 1; i < T; i++)
        ans += abs(stack[i] - stack[i + 1]);
    printf("%.2lf", ans);
    return 0;
}