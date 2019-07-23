/*
BOJ 11279 Max Heap 최대 힙

배열을 사용하여 max heap 직접 구현
*/
#include <stdio.h>
#define HEAP_SIZE 100000

int heap[HEAP_SIZE + 1];
int count = 0;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void push(int n) {
  heap[++count] = n;
  int idx = count;

  while(idx > 1 && heap[idx / 2] < heap[idx]) {
    swap(&heap[idx / 2], &heap[idx]);
    idx /= 2;
  }
}

int pop() {
  if(count == 0 ) return 0;
  
  int ret = heap[1];
  swap(&heap[1], &heap[count]);
  count--;

  int parent = 1;
  int child = parent * 2;
  if(child + 1 <= count) {
    child = heap[child] > heap[child + 1] ? child : child + 1;
  }

  while(child <= count && heap[parent] < heap[child]) {
    swap(&heap[parent], &heap[child]);
    parent = child;
    child = parent * 2;
    if(child + 1 <= count) {
      child = heap[child] > heap[child + 1] ? child : child + 1;
    }
  }
  return ret;
}

int main() {
  int N, i, num;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    scanf("%d", &num);
    if(num == 0) {
      printf("%d\n", pop());
    } else {
      push(num);
    }
  }
  return 0;
}
