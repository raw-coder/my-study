/*
BOJ 10818 최대, 최소
*/

#include <stdio.h>
int main() {
  int n, i, a;
  int max = -1234567, min = 1234567;

  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    scanf("%d", &a);
    max = a > max ? a : max;
    min = a < min ? a : min;
  }
  printf("%d %d", min, max);
  return 0;
}