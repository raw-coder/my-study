/*
BOJ 2552 별찍기 12
*/
#include <stdio.h>

int n, i, j;

void draw() {
  for(j = 1; j <= n - i; j++) {
    printf(" ");
  }
  for(j = 1; j <= i; j++) {
    printf("*");
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    draw();
  }
  for(i = n - 1; i >= 1; i--) {
    draw();
  }
  return 0;
}