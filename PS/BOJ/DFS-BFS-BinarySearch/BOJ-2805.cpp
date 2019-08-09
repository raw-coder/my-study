/*
BOJ 2805 나무 자르기
*/

#include <stdio.h>
#include <algorithm>
#define MAX_SIZE 1000000

using namespace std;

int A[MAX_SIZE + 1];
int N, M;

int search(int target, int size) {
  int left = 1;
  int right = size;
  int mid, i;
  long long sum = 0;
  while(left <= right) {
    mid = (left + right) / 2;
    for(i = 1; i <= N; i++) {
      sum += A[i] > mid ? A[i] - mid : 0;
    }
    if(sum < target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
    sum = 0;
  }
  return right;
}

int main() {
  scanf("%d %d", &N, &M);
  int i;
  int max = 0;
  for(i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    max = A[i] > max ? A[i] : max;
  }
  sort(A + 1, A + N + 1);
  printf("%d\n", search(M, max));
  return 0;
}
