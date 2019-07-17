/*
하노이 타워

*/
#include <stdio.h>

// from의 원반 n개를 by를 거쳐 to로 이동
void hanoi(int n, char from, char by, char to) {
  if(n == 1) {
    printf("원반 1을 %c에서 %c로 이동\n", from, to);
  } else {
    hanoi(n - 1, from, to, by);
    printf("원반 %d를 %c에서 %c로 이동!\n", n, from, to);
    hanoi(n - 1, by, from, to);
  }
}

int main() {
  hanoi(3, 'A', 'B', 'C');
  return 0;
}