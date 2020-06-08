#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;
struct Node{
	int a;int b;int cost;
};
Node node[100005];
int par[10005],river[10005];

int cmp(const void*a, const void *b){
    return ((Node*)a)->cost - ((Node*)b)->cost;
}

void init(int n){
	for(int i = 0;i < n;i++){
		par[i] = i;
	}
}

int find(int x){
	if(x == par[x]) return x;
	return find(par[x]);
}

void join(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y) return ;
	par[x] = y;
}

int kruskal(int n,int m){
	int sum = 0,num = 0;
	qsort(node,n,sizeof(node[0]),cmp);
	for(int i = 0;i < m;i++){
		cout<<node[i].a<<" "<<node[i].b<<endl;
	}
	cout<<endl;
	for(int i = 0; i < m && num != n - 1; i++){
        if(find(node[i].a) != find(node[i].b)){
            join(node[i].a, node[i].b);
			/*if(river[node[i].a] != -1 && river[node[i].b] != -1){
				sum += min(river[node[i].a] + river[node[i].b],node[i].cost);
			}
			else{*/
			cout<<node[i].a<<" "<<node[i].b<<endl; 
			sum += node[i].cost;
			//}
            num++;
        }
    }
    return sum;
}

int main(){
	int n,m;
	cin>>n>>m;
	init(n);
	for(int i = 0;i < m;i++){
		scanf("%d %d %d",&node[i].a,&node[i].b,&node[i].cost);
	}
	/*for(int i = 1;i <= n;i++){
		cin>>river[i];
	}*/
	cout<<endl;
	int res = kruskal(n,m);
	cout<<res<<endl;
	return 0;
}