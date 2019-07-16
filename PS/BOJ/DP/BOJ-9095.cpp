/*
BOJ 9095 1,2,3 더하기

f(n) = f(n - 1) + f(n - 2) + f(n - 3)

점화식 근거 :
n - 1 까지의 조합 + 1
n - 2 까지의 조합 + 2
n - 3 까지의 조합 + 3
===> n 까지의 조합
*/
#include <stdio.h>

int dp[11] = {0, 1, 2, 4, 7,};

int f(int n) {
  if(dp[n] > 0) return dp[n];
  dp[n] = f(n - 1) + f(n - 2) + f(n - 3);
  return dp[n];
}

int main() {
  int T, N;
  scanf("%d", &T);
  for(int i = 1; i <= T; i++) {
    scanf("%d", &N);
    printf("%d\n", f(N));
  }
  return 0;
}