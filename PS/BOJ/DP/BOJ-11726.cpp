/*
BOJ 11726 2xn 타일링
f(n) = f(n-1) + f(n-2) 
*/
#include <stdio.h>

int cache[1001] = {0,};

int dp(int n) {
  if(cache[n] != 0) return cache[n];
  cache[n] = (dp(n - 1) + dp(n -2)) % 10007;
  return cache[n];
}

void init() {
  cache[1] = 1;
  cache[2] = 2;
}

int main() {
  init();
  int N;
  scanf("%d", &N);
  printf("%d", dp(N));
  return 0;
}