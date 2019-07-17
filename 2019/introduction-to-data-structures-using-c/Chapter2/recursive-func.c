#include <stdio.h>

void recursive(int num) {
  if(num <= 0) { // 재귀함수 탈출조건
    return;
  }
  printf("function is called : %d\n", num);
  recursive(num - 1);
}

int main() {
  recursive(3);
  return 0;
}