#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
  int xpos, ypos;
} Point;

// Point 변수의 xpos, ypos 설정
void setPointPos(Point *ppos, int xpos, int ypos);

// Point 변수의 xpos, ypos 값 출력
void showPointPos(Point *ppos);

// 두 Point 비교
// x만 같으면 1, y만 같으면 2, 모두 같으면 0, 모두 다르면 -1 
int comparePoints(Point *ppos1, Point *ppos2);

#endif