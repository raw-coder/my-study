/*
BOJ 2438 별찍기1
*/
#include <stdio.h>
int main() {
  int n, i, j;
  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= i; j++) {
      printf("*");
    }
    printf("\n");
  }
}