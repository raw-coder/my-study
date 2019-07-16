/*
BOJ 2156 포도주 시식

dp[i] : i번째 와인잔까지의 포도주량 합계 최대값
c[i] : i번째 와인잔의 포도주 양

dp[i] = max(dp[i - 1], dp[i - 2] + c[i], dp[i - 3] + c[i - 1] + c[i])
*/
#include <stdio.h>
int max(int a, int b) {
  return (a > b) ? a : b;
}

int dp[10001], c[10001];

int main() {
  int N, i;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    scanf("%d", &c[i]);
    if(i == 1) {
      dp[1] = c[1];
    } else if(i == 2) {
      dp[2] = c[1] + c[2];
    } else {
      dp[i] = max(max(dp[i - 1], dp[i - 2] + c[i]), dp[i - 3] + c[i - 1] + c[i]);
    }
  }
  printf("%d", dp[N]);
  return 0;
}