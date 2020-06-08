#include<cstdio>  
int main()  
{  
    int a[100][100],x;
    int i,j,m,n,q,temp;  
    scanf("%d",&q);
    for (int asd = 1; asd <= q; asd ++)
    {    
        scanf("%d",&x); 
        for(i = 0;i < x;i ++) 
            for(j = 0;j < x;j ++)  
                a[i][j] = 0;  
        i = 0;  
        j = x / 2;  
        a[i][j] = 1;  
        for(temp = 2; temp <= x * x; temp ++)  
        {  
            m = i;  
            n = j;  
            i --;  
            j ++;  
            if(i < 0)  
                i = x - 1;  
            if(j >= x)  
                j = 0;  
            if(a[i][j] != 0)  
            {  
                i = m + 1;  
                j = n;  
            }  
            a[i][j] = temp;  
        }  
        for(i = 0; i < x; i ++)  
        {  
            for(j = 0; j < x-1;j ++)  
                printf("%d ",a[i][j]);  
            printf("%d\n",a[i][x-1]);
        }  
    }  
}  