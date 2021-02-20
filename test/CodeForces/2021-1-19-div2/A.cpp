#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define MAXN 100010
using namespace std;
int qwe;
string s;
int main() {
  scanf("%d", &qwe);
  for (int www = 1; www <= qwe; www++) {
    int n;
    scanf("%d", &n);
    cin >> s;
    // cout << s;
    // cout << " ********";
    cout << "1";
    char ch = s[0] + 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == '0') {
        if (ch == '0' || ch == '2') {
          cout << "1";
          ch = '1';
          continue;
        }
        if (ch == '1') {
          cout << "0";
          ch = '0';
          continue;
        }
      }
      if (s[i] == '1') {
        if (ch == '0' || ch == '1') {
          cout << "1";
          ch = '2';
          continue;
        }
        if (ch == '2') {
          cout << "0";
          ch = '1';
          continue;
        }
      }
      // printf("*%c  \n  ", s[i]);
    }
    puts("");
  }
}
