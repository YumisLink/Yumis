#include <time.h>

#include <cstdio>
#include <iostream>
#include <random>
#include <utility>
using namespace std;
int cnt = 0, six = 200, five = 1000, four = 5000, c6, c5, c4, c3;
int c20, c40, c60, c80, c100, c120, c180, c240;
int a1, a2, a3;
int main() {
  srand(time(0));
  for (int j = 0; j < 500000; j++) {
    /* code */
    cnt = 0;
    a1 = false;
    a2 = false;
    a3 = false;
    int n;
    // printf("����鿨�Ĵ���:");
    // scanf("%d",&n);
    n = 10000;
    // puts("");
    for (int i = 1; i <= n; i++) {
      int a = rand() % 10000;
      if (a < 200 + max(0, cnt - 50) * 200 || i == 120) {
        cnt = 0;
        c6++;
        if (rand() % 10000 < 5000 || i == 120) {
          a1++;
        }
      } else {
        cnt++;
        if (a > 10000 - five) {
          c5++;
          if (rand() % 10000 < 5000) {
            if (rand() % 2 == 0)
              a2++;
            else
              a3++;
          }
        } else if (a > 10000 - five - four)
          c4++;
        else
          c3++;
      }
      if (a1 && a2 && a3) {
        n = i;
        break;
      }
    }
    char c = '%';
    // puts("���շ���");
    // printf("���up���Ǻ�˫����ʱ��鿨����:%d", n);
    if (n <= 20) c20++;
    if (n <= 40) c40++;
    if (n <= 60) c60++;
    if (n <= 80) c80++;
    if (n <= 100) c100++;
    if (n <= 120) c120++;
    if (n <= 180) c180++;
    if (n <= 240) c240++;

    // printf("����������%d  �ۺϸ��ʣ�%.3f%c\n",c6,((float)c6/(float)n) *
    // 100,c); printf("����������%d  �ۺϸ��ʣ�%.3f%c\n",c5,((float)c5/(float)n)
    // * 100,c); printf("����������%d
    // �ۺϸ��ʣ�%.3f%c\n",c4,((float)c4/(float)n) * 100,c);
    // printf("����������%d  �ۺϸ��ʣ�%.3f%c\n",c3,((float)c3/(float)n) *
    // 100,c);
  }
    char c = '%';
  printf("���up���Ǻ�˫����ʱ��鿨����С��   20:%d�����ʣ�%.3f%c\n", c20,(float)c20/500000.0 * 100,c);
  printf("���up���Ǻ�˫����ʱ��鿨����С��   40:%d�����ʣ�%.3f%c\n", c40,(float)c40/500000.0 * 100,c);
  printf("���up���Ǻ�˫����ʱ��鿨����С��   60:%d�����ʣ�%.3f%c\n", c60,(float)c60/500000.0 * 100,c);
  printf("���up���Ǻ�˫����ʱ��鿨����С��   80:%d�����ʣ�%.3f%c\n", c80,(float)c80/500000.0 * 100,c);
  printf("���up���Ǻ�˫����ʱ��鿨����С��  100:%d�����ʣ�%.3f%c\n", c100,(float)c100/500000.0 * 100,c);
  printf("���up���Ǻ�˫����ʱ��鿨����С��  120:%d�����ʣ�%.3f%c\n", c120,(float)c120/500000.0 * 100,c);
  printf("���up���Ǻ�˫����ʱ��鿨����С��  180:%d�����ʣ�%.3f%c\n", c180,(float)c180/500000.0 * 100,c);
  printf("���up���Ǻ�˫����ʱ��鿨����С��  240:%d�����ʣ�%.3f%c\n", c240,(float)c240/500000.0 * 100,c);

}