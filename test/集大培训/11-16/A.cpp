#include<cstdio>
#include<iostream>
#define PI 3.1415927
int main ()
{
    double a;
    while(scanf("%lf",&a) != EOF)
    {
        printf("%.3lf\n",4*a*a*a/3*PI);
    }
}