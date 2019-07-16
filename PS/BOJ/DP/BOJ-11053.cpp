/*
BOJ 11053 가장 긴 증가하는 부분 수열
*/

#include <stdio.h>

short c[1001];

int main() {
  int N, i;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    scanf("%d", &c[i]);
  }
  return 0;
}