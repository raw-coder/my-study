/*
BOJ 10844 쉬운 계단 수

f(n, d) ; n 자리수, 마지막 숫자 d
= f(n - 1, 1), for d = 0
+ f(n - 1, 8), for d = 9
+ f(n - 1, i +- 1), for d=[1,8]

출력 데이터 타입 long 으로 지정!
- int : -2,147,483,648 ~ 2,147,438,647

TODO : for 문으로만 dp 생성하도록 fix
*/
#include <stdio.h>
int dp[101][10] = {{0},{0, 1, 1, 1, 1, 1, 1, 1, 1, 1}, };
int div = 1000000000;

int f(int n, int d) {
  if(dp[n][d] > 0 || n == 1) return dp[n][d];
  if(d == 0) {
    dp[n][d] = f(n - 1, 1) % div;
  } else if(d == 9) {
    dp[n][d] = f(n - 1, 8) % div;
  } else {
    dp[n][d] = (f(n - 1, d - 1) + f(n - 1, d + 1)) % div;
  }
  return dp[n][d];
}

int main() {
  int N, i;
  long sum = 0;
  scanf("%d", &N);
  for(i = 0; i <= 9; i++) {
    sum += f(N, i);
  }  
  printf("%ld", sum % div);
  return 0;
}