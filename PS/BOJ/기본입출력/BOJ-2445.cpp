/*
BOJ 2445 별찍기8
*/
#include <stdio.h>

int n, i, j;

void drawLine() {
  int j;
  for(j = 1; j <= i; j++) {
    printf("*");
  }
  for(j = 1; j <= (n - i) * 2; j++) {
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
    drawLine();    
  }
  for(i = n - 1; i >= 1; i--) {
    drawLine();
  }
  return 0;
}

