/*
BOJ 2698 인접한 비트의 개수
// dp[n][k][0 or 1] 0 또는 1로 끝나는 n 자리수 인접비트 k 인 수열의 갯수
*/
#include <stdio.h>

int dp[101][101][2]; 

int main() {
  int T, n, k, i, j;
  dp[1][0][0] = 1;
  dp[1][0][1] = 1;
  dp[1][1][0] = 0;
  dp[1][1][1] = 0;
  for(i = 2; i <= 100; i++) {
    for(j = 0; j <= i - 1; j++) {
      dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
      dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0]; 
    }
  }
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &n, &k);
    printf("%d\n", dp[n][k][0] + dp[n][k][1]);
  }
  return 0;
}