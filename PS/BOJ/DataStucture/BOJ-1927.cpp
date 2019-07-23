/*
BOJ 1927 min heap 최소 힙

배열을 사용하여 min heap 직접 구현
*/

#include <stdio.h>
#define HEAP_SIZE 100000

void swap(int * a, int * b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int heap[HEAP_SIZE + 1];
int count = 0;

void push(int num) {
  heap[++count] = num;

  int child = count;
  int parent = child / 2;
  while(parent >= 1 && heap[parent] > heap[child]) {
    swap(&heap[parent], &heap[child]);
    child = parent;
    parent = child / 2;
  }
}

int pop() {
  if(count == 0) return 0;

  int ret = heap[1];

  swap(&heap[1], &heap[count]);
  count--;

  int parent = 1;
  int child = parent * 2;
  if(child + 1 <= count) {
    child = heap[child] < heap[child + 1] ? child : child + 1;
  }

  while(child <= count && heap[parent] > heap[child]) {
    swap(&heap[parent], &heap[child]);

    parent = child;
    child = parent * 2;
    if(child + 1 <= count) {
      child = heap[child] < heap[child + 1] ? child : child + 1;
    }
  }
  return ret;
}
int main() {
  int n, num;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &num);
    if(num == 0) {
      printf("%d\n", pop());
    } else  {
      push(num);
    }
  }
  return 0;
}