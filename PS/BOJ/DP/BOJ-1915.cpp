/*
BOJ 1915 가장 큰 정사각형


*/
#include <stdio.h>

int mat[1000][1000], dp[1000][1000];

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int n, m;
  int max = -1;
  int l, u;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      scanf("%1d", &mat[i][j]);
      if(i == 0 || j == 0) {
        dp[i][j] = mat[i][j];
      } else if(mat[i][j] == 1) {
        dp[i][j] = min(dp[i -1][j -1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
      } else {
        dp[i][j] = 0;
      }
      max = max < dp[i][j] ? dp[i][j] : max;
    }
  }
  printf("%d\n", max * max);
  return 0;
}
