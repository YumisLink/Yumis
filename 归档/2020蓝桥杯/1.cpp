#include<bits/stdc++.h>
using namespace std;

long double s[1010][2];//存储直线的A，B 
long long ans;
bool st[1010]; //false表示不是重边 
pair<long double,long double> p;

int main(){
  freopen("6.in","r",stdin);
  freopen("6.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i][0]>>s[i][1];
		set<pair<long double,long double> > points;
		for(int j=0;j<i;j++){
			if(st[j])continue;//直线是重边，跳过 
			if(s[i][0]==s[j][0]){//两条直线斜率相等时，判断是平行还是重合 
				if(s[i][1]==s[j][1]){
					st[i]=true;//待添加直线是重边，退出循环 
					break;
				}else continue;//直线平行，不需要计算交点 
			}
			p.first=(s[j][1]-s[i][1])/(s[i][0]-s[j][0]);//交点的x坐标 
			p.second=s[i][0]*p.first+s[i][1];//交点的y坐标 
			points.insert(p);
		}
		if(!st[i])ans+=points.size()+1;//若当前直线不是重边，更新答案 
	}
	cout<<ans+1;
	return 0;
}