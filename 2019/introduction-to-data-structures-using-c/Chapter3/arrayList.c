#include <stdio.h>
#include "arrayList.h"

void Linit(List * plist) {
  plist->numOfData = 0;
  plist->curPosition = -1;
}

void Linsert(List * plist, Ldata data) {
  if(plist->numOfData >= LIST_LEN) {
    printf("overflow"); 
    return;
  }
  plist->arr[plist->numOfData] = data;
  plist->numOfData++;
  
}

int Lfirst(List * plist, Ldata * pdata) {
  if(plist->numOfData == 0) return FALSE;
  plist->curPosition = 0;  // 참조 위치 초기화
  *pdata = plist->arr[0];  // pdata가 가르키는 공간에 데이터 저장
  return TRUE;
}

int Lnext(List * plist, Ldata * pdata) {
  if(plist->curPosition >= plist->numOfData - 1) return FALSE;
  plist->curPosition++;
  *pdata = plist->arr[plist->curPosition];
  return TRUE;
}

Ldata Lremove(List * plist) {
  int rpos = plist->curPosition; // 삭제할 데이터의 인덱스
  int num = plist->numOfData;
  int i;
  Ldata rdata = plist->arr[rpos]; // 삭제할 데이터 임시 저장

  for(i = rpos; i <= num; i++) {
    plist->arr[i] = plist->arr[i + 1];
  }
  plist->numOfData--;
  plist->curPosition--;
  return rdata;
}

int Lcount(List * plist) {
  return plist->numOfData;
}