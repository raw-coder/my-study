#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

ll tree[100000 * 4];
ll lazy[100000 * 4];

void update_lazy(int node, int start, int end) {
  if(lazy[node] != 0) {
    tree[node] += (end - start + 1) * lazy[node];
    if(start != end) {
      lazy[node * 2] = lazy[node];
      lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
  }
}

void update_range(int node, int start, int end, int left, int right, ll diff) {
  update_lazy(node, start, end);
  if(left > end || right < start) return;
  if(left <= start && end <= right) {
    tree[node] += (end - start + 1) * diff;
    if(start != end) {
      lazy[node * 2] = diff;
      lazy[node * 2 + 1] = diff;
    }
  }
  int mid = (end - start) / 2;
  update_range(node * 2, start, mid, left, right, diff);
  update_range(node * 2 + 1, mid + 1, end, left, right, diff);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(int node, int start, int end, int left, int right) {
  update_lazy(node, start, end);
  if(left > end || right < start) return 0;
  if(left <= start && end <= right) return tree[node];
  int mid = (start + end) / 2;
  return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
