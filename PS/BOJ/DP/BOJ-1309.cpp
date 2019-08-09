/*
BOJ 1309 동물원
dp[n][0] : 마지막 배치가 X X 인 경우의 수
dp[n][1] : 마지막 배치가 X O 인 경우의 수
dp[n][2] : 마지막 배치가 O X 인 경우의 수
*/
#include <stdio.h>

int dp[100001][3];

int main() {
  int N, i, temp;
  scanf("%d", &N);
  dp[1][0] = 1;
  dp[1][1] = 1;
  dp[1][2] = 1;
  for(i = 2; i <= N; i++) {
    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
    dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
    dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901; 
  }
  printf("%d\n", (dp[N][0] + dp[N][1] + dp[N][2]) % 9901);
  return 0;
}