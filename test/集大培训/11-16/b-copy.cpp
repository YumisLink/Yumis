#include<iostream>  
#include<cstdio>
#include<algorithm>  
#include<cstring>
using namespace std;
int main() 
{
	int L, N, C, T, VR, VT1, VT2;
	int p[110];
	double dp[110];
	while (cin>>L) 
	{
		memset(dp, 0xfffffff, sizeof(dp));
		memset(p, 0, sizeof(p));
		cin >> N >> C >> T >> VR >> VT1 >> VT2;	
		p[0] = 0; p[N + 1] = L; dp[0] = 0;
		for (int i = 1; i <= N; i++) 
		{
			cin >> p[i];
		}
		double rabbit = (L*1.0) / VR;
		for (int i = 1; i <= N + 1; i++)//终点看成最后一个加油站为止；   
			for (int j = 0; j < i; j++) 
			{
				double temp;
				if (p[i] - p[j] <= C) 
				{
					temp = (p[i] - p[j])*1.0 / VT1 + T;
				}
				else 
				{
					temp = (C*1.0 / VT1) + (p[i] - p[j] - C)*1.0 / VT2 + T;
				}
				if (!j) 
				{
					temp -= T;
				}
				dp[i] = min(dp[j] + temp, dp[i]);
			}
		if (dp[N + 1] < rabbit) 
		{
			cout << "What a pity rabbit!" << endl;
		}
		else 
		{
			cout << "Good job,rabbit!" << endl;
		}
        printf("%lf   %lf\n",dp[N+1],rabbit);
	}
	return 0;
}