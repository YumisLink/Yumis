#include <cstdio>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
const double PI = acos(-1);
using namespace std;
using namespace std::chrono;
struct vector2
{
    double x, y;
};
struct line
{
    vector2 a, b;
};
vector2 make_vector2(double a, double b) { return (vector2){a, b}; }
vector<vector2> v;
queue<vector2> Q, W;

vector2 operator+(vector2 A, vector2 B) { return make_vector2(A.x + B.x, A.y + B.y); }
vector2 operator-(vector2 A, vector2 B) { return make_vector2(A.x - B.x, A.y - B.y); }
vector2 operator-(vector2 A) { return make_vector2(-A.x, -A.y); }
vector2 operator*(vector2 A, double m) { return make_vector2(A.x * m, A.y * m); }
vector2 operator*(double m, vector2 A) { return make_vector2(A.x * m, A.y * m); }
double cross(vector2 A, vector2 B) { return A.x * B.y - A.y * B.x; }                                                                                      //叉乘
double dot(vector2 A, vector2 B) { return A.x * B.x + A.y * B.y; }                                                                                        //点乘
double length(vector2 A) { return sqrt(A.x * A.x + A.y * A.y); }                                                                                          //求模
double angle(vector2 A, vector2 B) { return acos((dot(A, B)) / (length(A) * length(B))); }                                                                // 求向量的夹角
vector2 normalize(vector2 vec) { return make_vector2(vec.x / length(vec), vec.y / length(vec)); }                                                         // 求向量的方向
vector2 rotate(vector2 raw, double radius) { return make_vector2(raw.x * cos(radius) - raw.y * sin(radius), raw.x * sin(radius) + raw.y * cos(radius)); } //向量旋转

double a, b;
double eps = 1;
// bool check(vector2 pit)
// {
//     int cntlef = 0;
//     double cty = pit.y;
//     double ctx = pit.x;
//     double a, b;
//     for (int i = 0; i < v.size() - 1; i++)
//     {
//         double mi = min(v[i].y, v[i + 1].y);
//         double mx = max(v[i].y, v[i + 1].y);
//         if (mi < cty && cty < mx)
//         {
//             a = (v[i + 1].y - v[i].y) / (v[i + 1].x - v[i].x);
//             b = v[i].y - a * v[i].x;
//             double x = (cty - b) / a;
//             if (x > ctx)
//                 cntlef++;
//         }
//     }
//     if (cntlef % 2 == 0)
//         return false;
//     else
//     {
//         return true;
//     }
// }
vector2 normal(int b)
{
    int a, c;
    if (b == 0)
        a = v.size() - 2;
    else
        a = b - 1;
    if (b == v.size() - 1)
        c = 1;
    else
        c = b + 1;

    vector2 fir, sec, ret;
    fir = v[b] - v[a];
    sec = v[c] - v[b];
    ret = ((v[a] + v[c]) * 0.5) - v[b];
    ret = normalize(ret);
    if (cross(fir, sec) < 0.0)
        return v[b] + ret;
    else
        return v[b] - ret;
    // lef = normalize(lef) * 0.2;
    // double ang = angle(lef, rig);
    // lef = rotate(lef, ang * 0.5 + PI / 2);
    // return v[b] + (lef * ret);
}
int main()
{
    freopen("data3.out", "r", stdin);
    freopen("line1.out", "w", stdout);
    while (scanf("%lf%lf", &a, &b))
    {
        if (a == 0 && b == 0)
            break;
        v.push_back(make_vector2(a, b));
    }
    v.push_back(v[0]);

    // printf("%d", check(make_vector2(1, 1)));
    // int qwe = 0;
    // time_point<high_resolution_clock> tyui = high_resolution_clock::now();

    int head = 0, back = 1;
    // while (1)
    // {
    //     while (length(v[head] - v[back]) <= eps)
    //         if (back + 1 <= v.size() - 1)
    //             back++;
    //         else
    //             break;
    //     if (back == v.size() - 1)
    //     {
    //         if (length(v[head] - v[back]) > eps)
    //             Q.push(v[head]);
    //         break;
    //     }
    //     Q.push(v[head]);
    //     head = back;
    //     back++;
    // }
    // v.clear();
    // while (!Q.empty())
    // {
    //     v.push_back(Q.front());
    //     Q.pop();
    // }
    // v.push_back(v[0]);
    bool flag = 0;
    // printf("%d", v.size());
    while (1)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            W.push(normal(i));
            // vector2 v12 = normal(i, 1);
            // printf("?\n");
            // if (!check(v12))
            // {
            //     W.push(v12);
            // }
            // v12 = normal(i, -1);
            // if (!check(v12))
            // {
            //     W.push(v12);
            // }
        }

        v.clear();
        while (!W.empty())
        {
            v.push_back(W.front());
            W.pop();
        }
        v.push_back(v[0]);

        // back = 1, head = 0;
        // while (back < v.size() - 1)
        // {
        //     while (length(v[head] - v[back]) <= eps)
        //         if (back + 1 <= v.size() - 1)
        //             back++;
        //         else
        //             break;
        //     if (back == v.size() - 1)
        //     {
        //         // if (length(v[head] - v[back]) > eps)
        //         Q.push(v[head]);
        //         // printf("12332133\n");
        //         break;
        //     }
        //     Q.push(v[head]);
        //     head = back;
        //     back++;
        // }

        // if (Q.size() <= 10)
        //     break;
        // v.clear();
        // while (!Q.empty())
        // {
        //     v.push_back(Q.front());
        //     Q.pop();
        // }
        // v.push_back(v[0]);
        // {
        for (int i = 0; i < v.size(); i++)
        {
            printf("%lf %lf\n", v[i].x, v[i].y);
        }
        printf("%lf %lf\n", v[0].x, v[0].y);
        printf("0.0 0.0\n");
        // }
        if (!flag)
            flag = 1;
        else
            break;
        // break;
    }

    // {
    //     printf("%lf %lf\n", Q.front().x, Q.front().y);
    //     Q.pop();
    // }

    // cout << qwe << "\n";
    // cout << duration_cast<microseconds>(high_resolution_clock::now() - tyui).count();
}