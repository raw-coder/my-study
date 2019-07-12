/*
BOJ 10992 별찍기 17
*/
#include <stdio.h>

int n, i, j;

void drawPreSpace() {
  for(j = n - i; j >= 1; j--) {
    printf(" ");
  }
}

void drawBetSpace() {
  for(j = 1; j <= 2 * (i - 1) - 1; j++) {
    printf(" ");
  }
}

void drawStars() {
  if(i != n){
    drawPreSpace();
    printf("*");
    if(i != 1) {
      drawBetSpace();
      printf("*");
    }
  } else {
    for(j = 1; j <= n * 2 - 1; j++) {
      printf("*");
    }
  }
  printf("\n");
}

int main() {
  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    drawStars();
  }
  return 0;
}