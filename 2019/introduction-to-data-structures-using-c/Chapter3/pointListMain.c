#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "point.h"

int main() {
  List list;
  Point compPos;
  Point * ppos;

  Linit(&list);

  // data 4개 생성, 저장
  ppos = (Point *)malloc(sizeof(Point));
  setPointPos(ppos, 2, 1);
  Linsert(&list, ppos);

  ppos = (Point *)malloc(sizeof(Point));
  setPointPos(ppos, 2, 2);
  Linsert(&list, ppos);

  ppos = (Point *)malloc(sizeof(Point));
  setPointPos(ppos, 3, 1);
  Linsert(&list, ppos);

  ppos = (Point *)malloc(sizeof(Point));
  setPointPos(ppos, 3, 2);
  Linsert(&list, ppos);

  // print
  printf("counts : %d\n", Lcount(&list));

  if(Lfirst(&list, &ppos)) {
    showPointPos(ppos);
    while(Lnext(&list, &ppos)) {
      showPointPos(ppos);
    }
  }
  printf("\n");

  // xpos = 2 인 데이터 삭제
  compPos.xpos = 2;
  compPos.ypos = 0;

  if(Lfirst(&list, &ppos)) {
    if(comparePoints(ppos, &compPos) == 1) {
      ppos = Lremove(&list);
      free(ppos);
    } 
    while(Lnext(&list, &ppos)) {
      if(comparePoints(ppos, &compPos) == 1) {
        ppos = Lremove(&list);
        free(ppos);
      } 
    }
  }

  // print
  printf("counts : %d\n", Lcount(&list));

  if(Lfirst(&list, &ppos)) {
    showPointPos(ppos);
    while(Lnext(&list, &ppos)) {
      showPointPos(ppos);
    }
  }
  printf("\n");

  return 0;
}