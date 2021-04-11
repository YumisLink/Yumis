#include "PainterEngine_Application.h"
#include "Graphic.h"

PX_Application App;

PointArray points;
int nowCnt = 0;
px_dword time = 0;
px_dword lastDraw = 0;

px_bool PX_ApplicationInitialize(PX_Application* pApp, px_int screen_width, px_int screen_height) {
  PX_ApplicationInitializeDefault(&pApp->runtime, screen_width, screen_height);
  points = KSGFK_LoadPoints("C:\\Users\\63569\\Desktop\\Yumis\\test\\line1.out");
  return PX_TRUE;
}

px_void PX_ApplicationUpdate(PX_Application* pApp, px_dword elpased) {
}

px_void PX_ApplicationRender(PX_Application* pApp, px_dword elpased) {  
  px_surface* pRenderSurface = &pApp->runtime.RenderSurface;
  PX_RuntimeRenderClear(&pApp->runtime, PX_COLOR(255, 255, 255, 255));
  time += elpased;
  if (time < lastDraw) return;
  lastDraw += 3;
  if (nowCnt < points.count) nowCnt++;
  const int offsetX = pRenderSurface->width / 2;
  const int offsetY = pRenderSurface->height / 2;
  const int scale = 40;
  for (int i = 1; i < nowCnt; i++) {
    Point* last = points.data + i - 1;
    Point* now = points.data + i;
    if (last->x == 0 || now->x == 0)
      continue;
    float x1 = (last->x * scale + offsetX);
    float y1 = (last->y * scale + offsetY);
    float x2 = (now->x * scale + offsetX);
    float y2 = (now->y * scale + offsetY);
    PX_GeoDrawLine(pRenderSurface, x1, y1, x2, y2, 5, PX_COLOR(255, 0, 0, 0));
  }
  // Point* last = points.data + points.count - 1;
  // Point* now = points.data;
  // float x1 = (last->x * scale + offsetX);
  // float y1 = (last->y * scale + offsetY);
  // float x2 = (now->x * scale + offsetX);
  // float y2 = (now->y * scale + offsetY);
  // PX_GeoDrawBresenhamLine(pRenderSurface, x1, y1, x2, y2, PX_COLOR(255, 0, 0, 0));
}

px_void PX_ApplicationPostEvent(PX_Application* pApp, PX_Object_Event e) {
  PX_ApplicationEventDefault(&pApp->runtime, e);
}
