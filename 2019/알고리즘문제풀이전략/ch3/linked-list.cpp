/*
코드 3-2
Linked list 의 삽입 알고리즘
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
  char Data;
  struct _NODE *Next;
} NODE;

NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);

void Initailize(void) {
    NODE *ptr;
    head = (NODE *) malloc(sizeof(NODE));
    end = (NODE *) malloc(sizeof(NODE));

    temp1 = (NODE *) malloc(sizeof(NODE));
    temp1->Data = 'A';
    head->Next = temp1;
    temp1->Next = end;
    end->Next = end;
    ptr = temp1;

    temp2 = (NODE *) malloc(sizeof(NODE));
    temp2->Data = 'B';
    ptr->Next = temp2;

}
