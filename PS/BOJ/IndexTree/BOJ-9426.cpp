/*
BOJ 9426 중앙값 측정
*/

#include <stdio.h>
#define MAX_NUMS 65536

int arr[250001];
int tree[MAX_NUMS * 4];

void update(int node, int start, int end, int idx, int delta) {
  if(idx < start || idx > end) return;
  tree[node] += delta;
  if(start == end) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, idx, delta);
  update(node * 2 + 1, mid + 1, end, idx, delta);
}

int kth(int node, int start, int end, int k) {
  if(start == end) return start;
  int mid = (start + end) / 2;
  if(k <= tree[node * 2]) return kth(node * 2, start, mid, k);
  else return kth(node * 2 + 1, mid + 1, end, k - tree[node * 2]);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int cnt = (k + 1) / 2;
  long long sum = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    update(1, 0, MAX_NUMS, arr[i], 1);
    if(i >= k) {
      if(i > k) {
        update(1, 0, MAX_NUMS, arr[i - k], -1);
      }
      sum += kth(1, 0, MAX_NUMS, cnt);
    }
  }
  printf("%lld", sum);
  return 0;
}