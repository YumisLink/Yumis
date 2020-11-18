#include <cstdio>
#include <algorithm>
#include <cmath>
#define MAXN (int)1e5 + 10
#define calc(a, b, c) (cross((b) - (a), (c) - (a)))
#define PI 
using namespace std;
struct Vector2{double x, y;};
double cross(Vector2 a, Vector2 b) { return a.x * b.y - a.y * b.x; }
double abs(Vector2 a) { return sqrt(a.x * a.x + a.y * a.y); }
Vector2 operator-(Vector2 A, Vector2 B) { return (Vector2){A.x - B.x, A.y - B.y}; }
bool operator<(Vector2 A, Vector2 B) { return A.x == B.x ? A.y < B.y : A.x < B.x; }
int n;
Vector2 stack[MAXN];
Vector2 pot[MAXN];
double ans = 0;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &pot[i].x, &pot[i].y);
    if (n < 3) 
    printf("-1");
    sort(pot + 1, pot + 1 + n);
    stack[1] = pot[1];
    stack[2] = pot[2];
    int top = 2;
    for (int i = 3; i <= n; i++)
    {
        while (top > 1 && calc(stack[top - 1], stack[top], pot[i]) <= 0)
            top--;
        stack[++top] = pot[i];
    }
    stack[++top] = pot[n-1];
    for (int i = n-2;i >= 1; i --)
    {
        while (top > 1 && calc(stack[top-1],stack[top],pot[i]) <= 0)
            top--;
        stack[++top] = pot[i];
    }
    for (int i = 2;i <= top; i ++)
        ans += abs(stack[i-1]-stack[i]);
    ans += abs(stack[top]-stack[1]);
    printf("%.2lf",ans);
}