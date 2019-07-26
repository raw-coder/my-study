/*
BOJ 2331 반복수열

99999 5
(9 ^ 5) * 5 = 295245 

2 ^ 5 
*/
#include <stdio.h>
#include <math.h>
#define MAX_SIZE 300000 // (9 ^ 5) * 5 = 295245 

int nums[MAX_SIZE];
int numVisited[MAX_SIZE];

int nextNum(int num, int p) {
  int ret = 0;
  while(num > 0) {
    ret += (int)pow(num % 10, p);
    num /= 10;
  }
  return ret;
}

void dfs(int num, int p) {
  numVisited[num]++;
  int next = nextNum(num, p);
  if(numVisited[next] == 2) return;
  dfs(next, p);
}

int main() {
  int A, P, i;
  int count = 0;
  scanf("%d %d", &A, &P);
  dfs(A, P);
  for(int i = 1; i <= MAX_SIZE; i++) {
    if(numVisited[i] == 1) count++;
  }
  printf("%d", count);
  return 0;
}
