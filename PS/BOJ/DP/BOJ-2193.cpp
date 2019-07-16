/*
BOJ 2193 이친수

dp[n][d] : n 자리수, 마지막 숫자 d
= dp[n - 1][0] + dp[n - 1][1] , if d = 0
= dp[n - 1][0], if d = 1  
*/

#include <stdio.h>
long dp[91][2];

int main() {
  int N, i;
  scanf("%d", &N);
  dp[1][0] = 0;
  dp[1][1] = 1;
  
  for(i = 2; i <= N ; i++) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }
  printf("%ld", dp[N][0] + dp[N][1]);
  return 0;
}