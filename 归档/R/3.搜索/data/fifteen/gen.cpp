#include <bits/stdc++.h>
int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int x=3,y=3;
void move()
{
	int d=rand()&3;
	int nx=x+dx[d],ny=y+dy[d];
	if(nx==-1||ny==-1||nx==4||ny==4)
		return;
	std::swap(a[x][y],a[nx][ny]);
	x=nx,y=ny;
}
int main(int argc,char**argv)
{
	srand(time(0));
	for(int i=atoi(argv[1]);i--;move());
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)printf("%d%c",a[i][j]," \n"[j==3]);
	//for(int i=0;i<16;++i)a[i]=i;
	//std::random_shuffle(a,a+16);
	//for(int i=0;i<16;++i)printf("%d%c",a[i]," \n"[i%4==3]);
}
