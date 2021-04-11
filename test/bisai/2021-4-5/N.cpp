#include <iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main (){
    int n,ans;
        while(cin>>n){
        ans=0;
        if(n%2)ans=0;
        else if(n%4==0)ans=2;
        else ans=1;
        cout<<ans<<endl;
    }

    return 0;
}