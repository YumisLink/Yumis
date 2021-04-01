#include <bits/stdc++.h>
using namespace std;

int main(){
	int sum = 0,c = 0,z = 0,n = 0;
	cin>>n;
	sum+=n*60;
	for(int i  = 0;i < n;i++)
	{
		int a,b;
		cin>>a>>b;
		sum-=a*20;
		c+=a;
		z+=b;
		if(c==z) sum-=30;
		else if(z<c/2) sum-=70;
	}
	if(sum == 0) cout<<"--"<<endl;
	else if(sum > 0) cout<<"+"<<sum<<endl;
	else cout<<sum<<endl;
	return 0;
}
