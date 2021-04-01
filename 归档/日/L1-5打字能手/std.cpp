#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int num[26] = { 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };        //26个字母打表需要按几次 
int main()
{
	int ans = 0;
	string a;
	getline(cin, a);
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 'a'&&a[i] <= 'z') ans += num[a[i] - 'a'];
		if (a[i] == ' ') ans++;
	}
	printf("%d", ans);
	return 0;
}