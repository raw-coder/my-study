/*
BOJ 10845 큐 Queue

*/
#include <stdio.h>
#include <string.h>

struct Queue {
  int queue[10000];
  int front=0, back=0;
  void push(int num) {
    queue[back++]=num;
  }
  void pop() {
    printf("%d\n", front<back?queue[front++]:-1);
  }
  void size() {
    printf("%d\n", back-front);
  }
  void empty() {
    printf("%d\n", back-front==0?1:0);
  }
  void qfront() {
    printf("%d\n", front<back?queue[front]:-1);
  }
  void qback() {
    printf("%d\n", front<back?queue[back-1]:-1);
  }
}; 

int main() {
  int N, i, x;
  Queue q;
  char c[6];
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    scanf("%s", c);
    if(strcmp(c, "push") == 0) {
      scanf("%d", &x);
      q.push(x);
    } else if(strcmp(c, "pop") == 0) {
      q.pop(); 
    } else if(strcmp(c, "size") == 0) {
      q.size();
    } else if(strcmp(c, "empty") == 0) {
      q.empty();
    } else if(strcmp(c, "front") == 0) {
      q.qfront();
    } else if(strcmp(c, "back") == 0) {
      q.qback();
    }
  }
  return 0;
}