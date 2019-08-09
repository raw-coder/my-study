/*
BOJ 1300 k번째 수

이분 탐색
*/

#include <stdio.h>
int N, k;

int min(int a, int b) {
  return a < b ? a : b;
}

int search(int target, int size) {
  int l = 1;
  int r = size;
  int m;
  int cnt = 0, i;
  int ret = 0;

  while(l <= r) {
    m = (l + r) / 2;
    for(i = 1; i <= N; i++) {
      cnt += min(m / i, N);
    }
    if(cnt < target) {
      l = m + 1;
    } else {
      r = m - 1;
      ret = m;
    } 
    cnt = 0;
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  scanf("%d", &k);

  printf("%d\n", search(k, k));
  return 0;
}
