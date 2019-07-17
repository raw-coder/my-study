/*
BOJ 1914 하노이 탑

1. N - 1 개를 1 -> (3을 거쳐서) 2로 이동
2. 1개를 1 -> 3 이동
3. (1에서 이동한) N - 1 개를 2 -> (1을 거쳐서) 3으로 이동
*/
#include <stdio.h>
int N;
long long cnt = 0;
long long dp[101];

long long hanoi(int n, int from, int by, int to) {
  if(n == 1) {
    if(N <= 20) printf("%d %d\n", from, to);
    return cnt++;
  } else {
    long long cnt1 = hanoi(n - 1, from, to, by);
    if(N <= 20) printf("%d %d\n", from, to);
    cnt++;
    long long cnt2 = hanoi(n - 1, by, from, to);
  }
}

int main() {
  scanf("%d", &N);
  hanoi(N, 1, 2, 3);
  if(N > 20) printf("%lld", cnt);
  return 0;
}