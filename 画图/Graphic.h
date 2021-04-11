#ifndef GRAPHIC_H
#define GRAPHIC_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _Point {
  float x;
  float y;
} Point;

typedef struct _PointArray {
  Point* data;
  int count;
} PointArray;

PointArray KSGFK_LoadPoints(const char* path);

#ifdef __cplusplus
}
#endif

#endif