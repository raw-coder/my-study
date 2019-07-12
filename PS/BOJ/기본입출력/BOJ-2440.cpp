/*
BOJ 2440 별찍기 3
*/
#include <stdio.h>

int main() {
  int n, i, j;
  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    for(j = n - i + 1; j >= 1; j--) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}