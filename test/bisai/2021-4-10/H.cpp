#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
#define MAXN 110
#define ll long long
using namespace std;
ll ans;
int main() {
  int n;
  cin>>n;
  ll x,y;
  while(n--){
    scanf("%lld%lld",&x,&y);
    if(x*y>ans)ans=x*y;
  }
  cout<<ans<<endl;

  return 0;
}