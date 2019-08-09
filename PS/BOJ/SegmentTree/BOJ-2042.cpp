/*
BOJ 2042 
*/
#include <stdio.h>
#define MAX_SIZE 1000000

typedef long long ll;

int N, M, K;
ll arr[MAX_SIZE * 4];

void update(int node, int start, int end, int position, int num, int old) {
  if(start == end) {
    arr[node] = num;
    return;
  }
  arr[node] = arr[node] - old + num;
  int mid = (start + end) >> 1;
  if(mid < position) { //  ==> right side
    update(node * 2 + 1, mid + 1, end, position, num, old);
  } else { //  ==> left side
    update(node * 2, start, mid, position, num, old);  
  }
}

ll sum(int node, int start, int end, int left, int right) {
  if(start == end) return arr[node];
  if(start == left && end == right) return arr[node];
  int mid = (start + end) >> 1;
  if(mid < left) { // right side
    return sum(node * 2 + 1, mid + 1, end, left, right);  
  } else if (mid < right) { // both side
    return sum(node * 2, start, mid, left, mid) + sum(node * 2 + 1, mid +1, end, mid + 1, right);
  } else { // left side
    return sum(node * 2, start, mid, left, right);
  }
}

int main() {
  int i, x, a, b, c;
  scanf("%d %d %d", &N, &M, &K);
  int idx = 2;
  while(idx < N) {
    idx = idx << 1;
  }
  for(i = idx; i <= idx + N - 1; i++) {
    scanf("%d", &x);
    arr[i] = x;
  }
  for(i = idx - 1; i >= 1; i--) {
    arr[i] = arr[i * 2] + arr[i * 2 + 1];
  }
  for(i = 1; i <= M + K; i++) {
    scanf("%d %d %d", &a, &b, &c);
    if(a == 1) {
      update(1, 1, idx, b, c, arr[idx + b -1]);
    } else {
      printf("%lld\n", sum(1, 1, idx, b, c));
    }
  }
  return 0;
}