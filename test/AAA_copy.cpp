#include <cstdio>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>
#include <queue>
#define eps 1e-13
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
double asd, nmb;
double cross(vector2 A, vector2 B) { return A.x * B.y - A.y * B.x; } //叉乘
double dot(vector2 A, vector2 B) { return A.x * B.x + A.y * B.y; }   //点乘
double abs(vector2 A) { return sqrt(A.x * A.x + A.y * A.y); }        //求模
vector2 operator+(vector2 A, vector2 B) { return make_vector2(A.x + B.x, A.y + B.y); }
vector2 operator-(vector2 A, vector2 B) { return make_vector2(A.x - B.x, A.y - B.y); }
vector2 operator-(vector2 A) { return make_vector2(-A.x, -A.y); }
vector2 operator*(vector2 A, double m) { return make_vector2(A.x * m, A.y * m); }
vector2 operator*(double m, vector2 A) { return make_vector2(A.x * m, A.y * m); }
bool check(vector2 pit)
{
    //    for (int i =)
}
double li_space = 0.2;
double x_max = -1000, y_max = -1000, x_min = 1000, y_min = 1000;
double max(double a, double b) { return a > b ? a : b; }
double min(double a, double b) { return a < b ? a : b; }
double lfabs(double a) { return a >= 0 ? a : -a; }
bool equal(double a, double b) { return lfabs(a - b) <= eps ? true : false; }
bool is_cross(double y1, double y2, double a)
{
    if (min(y1, y2) < a && max(y1, y2) > a)
        return true;
    else
        return false;
}
double cross_x(vector2 a, vector2 b, double t) //两点坐标及直线y=t的参数t 使用前应检测是否相交
{
    double s, d; //交点x坐标 y=kx+b x=sy+d
    s = (b.x - a.x) / (b.y - a.y);
    d = a.x - s * a.y;
    return t * s + d;
}
int main()
{
    priority_queue<double> pQ_x;
    queue<line> Q;
    freopen("data1.out", "r", stdin);
    int calc = 0;
    while (scanf("%lf%lf", &asd, &nmb))
    {

        v.push_back(make_vector2(asd, nmb));
        if (asd == 0.0 && nmb == 0.0)
        {
            calc++;
        }
        if (calc == 4)
            break;
    }
    v.push_back(make_vector2(0.0, 0.0));
    int qwertyuiop = 0;
    time_point<high_resolution_clock> asdfghjkl = high_resolution_clock::now();
    // freopen("CON","r",stdin);
    for (int i = 0; i < v.size() - 1; i++)
    {
        x_max = max(x_max, v[i].x);
        x_min = min(x_min, v[i].x);
        y_max = max(y_max, v[i].y);
        y_min = min(y_min, v[i].y);
    }
    printf("%lf %lf\n%lf %lf\n", x_max, x_min, y_max, y_min);
    //	vector2 aa=make_vector2(0,0),bb=make_vector2(1,1);
    //	printf("%lf\n",cross_x(aa,bb,0.5));
    //	printf("%d",v.size());
    //	for(int j=0;j<v.size()-1;j++)
    //	{
    //		printf("%lf %lf\n",v[j].x,v[j].y);
    //		if(v[j].x==0.0&&v[j].y==0.0)
    //			getchar();
    //	}
    for (double i = y_min; i <= y_max; i += li_space) //i->x
    {
        int menr = -1;                         //记忆
        for (int j = 0; j < v.size() - 1; j++) //j->vector2
        {
            if (menr == -1)
                menr = j;
            if ((v[j + 1].x == 0.0 && v[j + 1].y == 0.0))
            {
                if (is_cross(v[j].y, v[menr].y, i)) //
                    pQ_x.push(cross_x(v[j], v[menr], i));
                menr = -1;
                j++;
                //				printf("0");
            }
            else if (is_cross(v[j].y, v[j + 1].y, i)) //
                pQ_x.push(cross_x(v[j], v[j + 1], i));
        }
        double fir = 0.0, sec = 0.0; //first second
        int flag = 0;
        while (!pQ_x.empty())
        {
            //			printf("%d",flag);
            if (flag)
            {
                sec = pQ_x.top();
                pQ_x.pop();
                //				if(lfabs(fir-sec)>(2*li_space))//useless
                //				{
                line tmp;
                tmp.a.x = fir;
                tmp.a.y = i;
                tmp.b.x = sec;
                tmp.b.y = i;
                Q.push(tmp);
                //				}
                //				printf("0");
            }
            else
            {
                fir = pQ_x.top();
                pQ_x.pop();
            }
            flag = !flag;
        }
    }
    // freopen("line2.out","w",stdout);
    // while(!Q.empty())
    // {
    // 	line tmp=Q.front();
    // 	Q.pop();
    // 	printf("%.9lf %.9lf\n%.9lf %.9lf\n",tmp.a.x,tmp.a.y,tmp.b.x,tmp.b.y);
    // 	printf("0.00000 0.00000\n");
    // }
    // freopen("CON","w",stdout);
    //    fclose(stdout);

    //
    cout << qwertyuiop << "\n";
    cout << duration_cast<microseconds>(high_resolution_clock::now() - asdfghjkl).count();
    return 0;
}