#include<stdio.h>
#define PI 3.14159
int main ()
{
    double r,a,c;
    printf ("input r=") ;
    scanf("%lf" ,&r) ;
    a=PI*r*r ;
    c=2*PI*r ;
    printf ("r=%f,a=%f,c=%f\n" ,r,a,c);
    return 0 ;
}
