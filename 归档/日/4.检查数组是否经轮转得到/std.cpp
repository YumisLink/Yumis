#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n = 0,nums[105];
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>nums[i];
	}
	int cnt= 0;
	for(int i = 0;i < n-1;i++)
	{
		if(nums[i] > nums[i+1])
		{
			cnt++;
		}
		if(cnt > 1)
		{
			cout<<"false"<<endl;
		}
	}
	if(nums[n-1] <= nums[0])
	{
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
}
