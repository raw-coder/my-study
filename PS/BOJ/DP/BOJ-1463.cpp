/*
BOJ 1463 1로 만들기
*/
#include<stdio.h>

int N, i;
int d[1000001] = {0};

int min(int x, int y) {
  return x < y ? x : y;
}

int min(int x, int y, int z) {
  return min(min(x, y), z);
}

int main() {
  scanf("%d", &N);

  d[2] = d[3] = 1;
  for(i = 4; i <= N; i++) {
    if(i % 2 == 0 && i % 3 == 0) d[i] = min(d[i / 3], d[i / 2], d[i -1]) + 1; 
    else if(i % 2 == 0) d[i] = min(d[i / 2], d[i - 1]) + 1;
    else if(i % 3 == 0) d[i] = min(d[i / 3], d[i -1]) + 1;
    else d[i] = d[i -1] + 1;
  }
  printf("%d", d[N]);
  return 0;
}