#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 100010
#define PI 3.141592653589793
#define calc(aa, bb, cc) (cross((bb) - (aa), (cc) - (bb)))

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
double a, b, r;
int main()
{
    scanf("%d%lf%lf%lf", &n, &b, &a, &r);
    a = a / 2.0;
    b = b / 2.0;
    for (int i = 1; i <= n; i++)
    {
        double x,y,t;
        scanf("%lf%lf%lf", &x, &y, &t);
        Vector2 add = (Vector2){x,y};
        p[++cnt] = rotate((Vector2){a-r, b-r}, t) + add;
        p[++cnt] = rotate((Vector2){r-a, b-r}, t) + add;
        p[++cnt] = rotate((Vector2){a-r, r-b}, t) + add;
        p[++cnt] = rotate((Vector2){r-a, r-b}, t) + add;
    }
    std::sort(p + 1, p + cnt + 1);
    stack[1] = p[1];
    stack[2] = p[2];
    int top = 2;
    for (int i = 3; i <= cnt; i++)
    {
        while (top > 1 && calc(stack[top - 1], stack[top], p[i]) <= 0)
            top--;
        stack[++top] = p[i];
    }
    int tmp = top;
    stack[++top] = p[cnt - 1];
    for (int i = cnt - 2; i >= 1; i--)
    {
        while (top > tmp && calc(stack[top - 1], stack[top], p[i]) <= 0)
            top--;
        stack[++top] = p[i];
    }
    double ans = 2.0 * PI * r;
    for (int i = 1; i < top; i++)
        ans += abs(stack[i] - stack[i+1]);
    printf("%.2lf", ans);
    return 0;
}