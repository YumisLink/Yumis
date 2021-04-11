#include <cstdio>
int a,b;
int main (){
  int ans = 0;
  scanf("%d%d",&a,&b);
  while (a != b)
  {
    if (a < b){
      ans += (b-a);
      a = b;
    }
    else{
      if (a % 2 == 0){
        a /= 2;
        ans++;
      }
      else{
        a ++;
        a /=2;
        ans += 2;
      }
    }
  }
  printf("%d",ans);
  
}