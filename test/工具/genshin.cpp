#include <time.h>

#include <cstdio>
#include <iostream>
#include <random>
#include <utility>
using namespace std;
int cnt = 0, five = 60, four = 510, c5, c4, c3, cnt4 = 0;
int main() {
  srand(time(0));
  int n;
  printf("����鿨�Ĵ���:");
  scanf("%d", &n);
  puts("");
  for (int i = 1; i <= n; i++) {
    int a = rand() % 10000;
    if (a < five + max(0, cnt - 73) * 600) {
      cnt = 0;
      c5++;
    } else {
      cnt++;
      if (a > 10000 - four || cnt4 == 10) {
        cnt4 = 0;
        c4++;
      } else {
        cnt4++;
        c3++;
      }
    }
  }
  char c = '%';
  // puts("ԭ��");
  printf("������ʱ��鿨����:%d",n);
  // printf("����������%d  �ۺϸ��ʣ�%.3f%c\n", c5, ((float)c5 / (float)n) * 100,
  //        c);
  // printf("����������%d  �ۺϸ��ʣ�%.3f%c\n", c4, ((float)c4 / (float)n) * 100,
  //        c);
  // printf("����������%d  �ۺϸ��ʣ�%.3f%c\n", c3, ((float)c3 / (float)n) * 100,
  //        c);
}