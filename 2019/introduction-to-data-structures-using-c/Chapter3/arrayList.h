#include "point.h"
#include "nameCard.h"
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define TRUE 1
#define FALSE 0

#define LIST_LEN 100
// typedef int Ldata;
// typedef Point * Ldata;
typedef NameCard * Ldata;
typedef struct __ArrayList {
  Ldata arr[LIST_LEN];
  int numOfData;
  int curPosition;  
} ArrayList;

typedef ArrayList List;

void Linit(List * plist);

void Linsert(List * plist, Ldata data);

int Lfirst(List * plist, Ldata * pdata);

int Lnext(List * plist, Ldata * pdata);

Ldata Lremove(List * plist);

int Lcount(List * plist);

#endif
