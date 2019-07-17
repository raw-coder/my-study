#include <stdio.h>
#include "point.h"

// Point 변수의 xpos, ypos 설정
void setPointPos(Point *ppos, int xpos, int ypos) {
  ppos->xpos = xpos;
  ppos->ypos = ypos;
}

// Point 변수의 xpos, ypos 값 출력
void showPointPos(Point *ppos) {
  printf("[%d, %d]\n", ppos->xpos, ppos->ypos);
}

// 두 Point 비교
// x만 같으면 1, y만 같으면 2, 모두 같으면 0, 모두 다르면 -1 
int comparePoints(Point *ppos1, Point *ppos2) {
  if(ppos1->xpos == ppos2->xpos && ppos1->ypos == ppos2->ypos) {
    return 0;
  } else if(ppos1->xpos == ppos2->xpos) {
    return 1;
  } else if(ppos1->ypos == ppos2->ypos) {
    return 2;
  } else {
    return -1;
  }
}


