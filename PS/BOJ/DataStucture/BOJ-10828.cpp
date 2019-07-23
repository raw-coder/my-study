/*
BOJ 10828 Stack 스택
*/
#include <stdio.h>
#include <string.h>

int s[10001];
int top = -1;

void push(int n) {
  s[++top] = n;
}
void pop() {
  printf("%d\n", top > -1 ? s[top--] : -1);
}
void size() {
  printf("%d\n", top + 1);
}
void empty() {
  printf("%d\n", top > -1 ? 0 : 1);
}
void sTop() {
  printf("%d\n", top > -1 ? s[top] : -1);
}

int main() {
  int N, i, num;
  char c[6];
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    scanf("%s", c);
    if(strcmp("push", c) == 0) {
      scanf("%d", &num);
      push(num);
    } else if(strcmp("pop", c) == 0) {
      pop();
    } else if(strcmp("size", c) == 0) {
      size();
    } else if(strcmp("empty", c) == 0) {
      empty();
    } else if(strcmp("top", c) == 0) {
      sTop();
    }
  }
  return 0;
}