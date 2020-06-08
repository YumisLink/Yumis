#include<stdio.h>
int main()
{
    int a,b,t;
    scanf ("%d%d", &a, &b) ;
    printf ( "Before exchanging: a=%d b=%d\n",a,b) ;
    t=a; 
    a=b; 
    b=t;
    printf ("After exchanging:a=%d b=%d\n" ,a,b) ;
    return 0;
}
