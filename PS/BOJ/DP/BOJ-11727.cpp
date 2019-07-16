/*
BOJ 11727 2xn 타일링 2
f(n) = f(n-1) + 2*f(n-2)

배열초기화 방법
- 중괄호 안에 index 순서대로 초기값 넣고 마지막 , 하면 
  입력한 값 이후 모든 값 0으로 초기화됨
*/

#include <stdio.h>

int dp[1001] = {0, 1, 3, };

int f(int n) {
  if(dp[n] != 0) return dp[n];
  dp[n] = (f(n - 1) + 2 * f(n - 2)) % 10007;
  return dp[n];
}

int main() {
  int N;
  scanf("%d", &N);
  printf("%d", f(N));
  return 0;
}