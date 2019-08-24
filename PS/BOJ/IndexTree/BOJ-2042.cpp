/*
BOJ 2042 구간합구하기

*/
#include <stdio.h>

long long tree[1000000 * 4];

void update(int node, int start, int end, int left, int right, int delta) {
  if(left > end || right < start) return;
  
  tree[node] += delta;
  if(left <= start && end <= right) return;
  int mid = (start + end) / 2;
  update(node * 2, start, mid, left, right, delta);
  update(node * 2 + 1, mid + 1, end, left, right, delta);
}

long long sum(int node, int start, int end, int left, int right) {
  if(left > end || right < start) return 0;
  if(left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
  int n, m, k;
  int a, b, c;
  scanf("%d %d %d", &n, &m, &k);

  int idx = 2;
  while(idx < n) {
    idx = idx << 1;
  }

  for(int i = idx; i <= idx + n - 1; i++) {
    scanf("%lld", &tree[i]);
  }
  for(int i = idx - 1; i >= 1; i--) {
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
  }

  for(int i = 1; i <= m + k; i++) {
    scanf("%d %d %d", &a, &b, &c);
    if(a == 1) {
      update(1, 1, idx, b, b, c - tree[idx + b - 1]);
    } else {
      printf("%lld\n", sum(1, 1, idx, b, c));
    }
  }
  return 0;
}