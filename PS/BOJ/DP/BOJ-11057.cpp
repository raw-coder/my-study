/*
BOJ 11057 오르막 수
dp[n][d] : n 자리수, 마지막 수 d
= sum[dp[n-1][i]] i = d...9 
*/
#include <stdio.h>

int dp[1001][10];
int div = 10007;

int main() {
  int N, i, j, k;
  scanf("%d", &N);
  for(i = 0; i <= 9; i++) {
    dp[1][i] = 1;  
  }
  for(i = 2; i <= N; i++) {
    for(j = 0; j <= 9; j++) {
      for(k = j; k <= 9; k++) {
        dp[i][j] += (dp[i - 1][k]) % div;
      }
    }
  }
  long sum = 0;
  for(i = 0; i <= 9; i++) {
    sum += dp[N][i];
  }
  printf("%ld", sum % div);
  return 0;
}