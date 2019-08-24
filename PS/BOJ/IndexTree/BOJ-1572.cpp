/*
BOJ 1572 중앙값
*/

#include <stdio.h>
#define MAX_NUM 66666
#define MAX_SIZE 250000

int tree[MAX_NUM * 4];
int arr[MAX_SIZE + 1];

void update(int node, int start, int end, int idx, int delta) {
  if(idx > end || idx < start) return;
  tree[node] += delta;
  if(start == end) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, delta);
  update(node * 2 + 1, mid + 1, end, idx, delta);
}

int kth(int node, int start, int end, int k) {
  if(start == end) return start;
  int mid = (start + end) / 2;
  if(tree[node * 2] >= k) {
    return kth(node * 2, start, mid, k);
  } else {
    return kth(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int cnt = (k + 1) / 2;
  int size = 2;
  while(size <= n) {
    size = size << 1;
  }
  long long sum = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    update(1, 0, MAX_NUM, arr[i], 1);
    if(i >= k) {
      if(i > k) update(1, 0, MAX_NUM, arr[i - k], -1);
      sum += kth(1, 0, MAX_NUM, cnt);
    }
  }
  printf("%lld\n", sum);
  return 0;
}