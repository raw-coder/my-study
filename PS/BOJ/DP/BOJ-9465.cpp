/*
BOJ 9465 스티커

dp[i][j] : col i의 j열(j=0,1) 스티커 선택(j=2 인 경우 선택하지 않음)
c[i][j] : i컬럼 j열 스티커 점수

dp[i][0] = max(dp[i-1][2], dp[i-1][1]) + c[i][0]
dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + c[i][1]
dp[i][2] = max(dp[i-1][0], dp[i-1][1])
*/

#include <stdio.h>

int dp[100001][3], c[100001][2];

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int T, N, t, i, j;
  scanf("%d", &T);
  for(t = 1; t <= T; t++) {
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
      scanf("%d", &c[i][0]);
    }
    for(i = 1; i <= N; i++) {
      scanf("%d", &c[i][1]);
    }
    for(i = 1; i<= N; i++) {
      dp[i][0] = max(dp[i-1][2], dp[i-1][1]) + c[i][0];
      dp[i][1] = max(dp[i-1][2], dp[i-1][0]) + c[i][1];
      dp[i][2] = max(dp[i-1][0], dp[i-1][1]);
    }
    printf("%d\n", max(max(dp[N][0], dp[N][1]), dp[N][2]));
  }
  return 0;
}