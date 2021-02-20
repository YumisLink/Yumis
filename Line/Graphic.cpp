#include "Graphic.h"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

_PointArray KSGFK_LoadPoints(const char* path) {
  ifstream f(path, ios::in);
  if (!f.is_open()) {
    cout << "can't open " << path << endl;
    return _PointArray{nullptr, 0};
  }
  vector<_Point> d;
  while (!f.eof()) {
    _Point t;
    f >> t.x >> t.y;
    d.push_back(t);
  }
  f.close();
  _PointArray arr;
  arr.data = new _Point[d.size()];
  arr.count = d.size();
  std::copy(d.begin(), d.end(), arr.data);
  return arr;
}