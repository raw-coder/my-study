/*
BOJ 1920 수 찾기

*/
#include <stdio.h>
#include <algorithm>
#define MAX_SIZE 100000

using namespace std;

int A[MAX_SIZE + 1], B[MAX_SIZE + 1];

int search(int target, int size) {
  int start = 1;
  int end = size;
  int mid;

  while(start <= end) {
    mid = (start + end) / 2;
    if(target < A[mid]) {
      end = mid - 1;
    } else if(target > A[mid]) {
      start = mid + 1;
    } else {
      return 1;      
    }
  }
  return 0;
}

int main() {
  int N, M, i;
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  scanf("%d", &M);
  for(i = 1; i <= M; i++) {
    scanf("%d", &B[i]);
  }
  sort(A + 1, A + N + 1);
  for(i = 1; i <= M; i++) {
    printf("%d\n", search(B[i], N + 1));
  }
  return 0;
}