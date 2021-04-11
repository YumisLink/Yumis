#include <cstdio>
#include <vector>
#include<map>
#include<cmath>
#include<iostream>
#define MAXN 20000010
using namespace std;
int n, a[MAXN];
  map<int,int>su;
int is(map<int,int>q1,map<int,int>q2){
  int x;
  //cout<<"is ing"<<endl;
  for(map<int,int>::iterator it=q1.begin();it!=q1.end();it++){
      if(q2[it->first]<it->second&&it->first!=1)return 0;
  }
  return 1;
}
void test(map<int,int>q){
    for(map<int,int>::iterator it=q.begin();it!=q.end();it++){
      cout<<it->first<<" : "<<it->second<<endl;
    }
}
void insert(int x,map<int,int>&q){
  //cout<<x<<"..."<<endl;
    for(map<int,int>::iterator it=su.begin();it!=su.end();it++){
      while(x%it->first==0){
        q[it->first]++;
        x/=it->first;
      }
      if(it->first*it->first>x){
        q[x]++;
        x=1;
        break;
      }
      if(x==1)break;
  }
  //cout<<"insert is ok"<<endl;
 // test(q);
}
int main() {
  su[2]++;
  int l1,r1,l2,r2,i;
  int genhaon=(int)sqrt(MAXN)+10;
  for(i=3;i<=genhaon;i++){
    int flag=1;
    for(map<int,int>::iterator it=su.begin();it!=su.end();it++){
      if(it->first*it->first>i)break;
      else if(i%it->first==0){
        flag=0;
        break;
      }
    }
    if(flag)su[i]++;
    //if(flag&&i<=100)cout<<i<<" "<<endl;
  }
  scanf("%d", &n);
  for (int qwe = 1; qwe <= n; qwe++) {
    map<int,int>q1,q2;
    
    scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
    for(i=l1;i<=r1;i++)if(i>=l2&&i<=r2)i=r2;else insert(i,q1);
    for(i=l2;i<=r2;i++)if(i>=l1&&i<=r1)i=r1;else insert(i,q2);
 //   test(q1);test(q2);
    if(is(q1,q2)==1)printf("Yes\n");
    else printf("No\n");
  }
}
