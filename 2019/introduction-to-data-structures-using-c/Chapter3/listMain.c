#include <stdio.h>
#include "arrayList.h"

int main() {
  // 생성, 초기화
  List list;
  int data;
  Linit(&list);

  // data 입력
  Linsert(&list, 11);
  Linsert(&list, 11);
  Linsert(&list, 22);
  Linsert(&list, 22);
  Linsert(&list, 33);

  // 데이터 출력
  printf("counts : %d\n", Lcount(&list));
  if(Lfirst(&list, &data)) {
    printf("%d ", data);
    while(Lnext(&list, &data)) {
      printf("%d ", data);
    }
  }
  printf("\n");

  // 데이터 탐색 후 삭제
  if(Lfirst(&list, &data)) {
    if(data == 22) {
      Lremove(&list);
    }
    while(Lnext(&list, &data)) {
      if(data == 22) {
        Lremove(&list);
      }
    }
  }

  // print
  printf("count : %d\n", Lcount(&list));
  if(Lfirst(&list, &data)) {
    printf("%d ", data);
    while(Lnext(&list, &data)) {
      printf("%d ", data);
    }
  }
  return 0;
}