#include <bits/stdc++.h>
char a[110][110];
int main(int argc,char **argv)
{
	int n=atoi(argv[1]),m=atoi(argv[2]),cas=atoi(argv[3]),rate=atoi(argv[4]);
	srand(time(0));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			a[i][j]='.';
	if(!cas)
		for(int i=n*m/rate;i--;a[rand()%n][rand()%m]='#');
	a[rand()%n][rand()%m]='S';
	a[rand()%n][rand()%m]='T';
	printf("%d %d\n",n,m);
	for(int i=0;i<n;++i)puts(a[i]);
}
