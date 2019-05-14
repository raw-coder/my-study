#include <stdio.h>

int main() {
  int sum = 0, i, score;
  for(i = 0; i < 5; i++) {
    scanf("%d", &score);
    sum += score > 40 ? score : 40;
  }
  printf("%d", sum / 5);
  return 0;
}