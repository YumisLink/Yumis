#include <stdio.h>
#include <stdlib.h>
struct str
{
    float height;
    char sex;
}q[100];
int main()
{
	int n,i;
	scanf("%d\n",&n);
	float height;
	char sex;
    for(i=0;i<n;i++)
	{
		scanf("%c %f\n",&q[i].sex,&q[i].height);
  }
    for(i=0;i<n;i++)
	{
		if(q[i].sex=='M')
		{
			printf("%.2f\n",(q[i].height/1.09));
		}
		else
		{
			printf("%.2f\n",(q[i].height*1.09));
		}
	}
	return 0;
}
