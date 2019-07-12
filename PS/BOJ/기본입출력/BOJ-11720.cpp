/*
BOJ 11720 숫자의 합

*/
#include <stdio.h>

int main() {
  int n, i, sum = 0;
  char str[101];
  scanf("%d", &n);
  scanf("%s", str);
  for(i = 0; i < n; i++) {
    sum += (str[i] - '0');
  }
  printf("%d", sum);
  return 0;
}