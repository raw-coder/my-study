/*
BOJ 2446 별찍기 9
*/
#include <stdio.h>
int n, i, j;

void draw() {
  for(j = 1; j <= n - i; j++) {
    printf(" ");
  }
  for(j = 1; j <= i * 2 - 1; j++) {
    printf("*");
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);
  for(i = n; i >= 1; i--) {
    draw();
  }
  for(i = 2; i <= n; i++) {
    draw();
  }
  return 0;
}