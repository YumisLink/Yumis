#include "bits/stdc++.h"
int main(int argc, char const *argv[])
{
	srand(time(0));
	int n=atoi(argv[1]);
	int m=atoi(argv[2])+1;
	for(printf("%d\n",n);n--;printf("%d %d\n",rand()%m,rand()%m));
	return 0;
}
