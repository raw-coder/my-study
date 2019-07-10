/*
2
5 8
1 1 5 1 3
1 2 5 2 5
1 1 4 3 4
1 1 3 2 2 
2 3 3 
2 5 2
2 1 5
3 1 4
5 15
1 1 4 1 9
1 1 5 2 5
1 1 5 3 5
1 2 4 1 8
1 2 4 2 8
2 1 3
3 1 1 
2 2 1
2 4 7
1 3 5 3 4
3 4 5
2 4 5
2 3 15
2 4 943
3 4 4

#1 5
#2 17

Segment Tree 구현
 */

#include <stdio.h>

int T, N, Q;
int SUM;
int p[3][100001];
long long data[100001];
long long tree[1048576]; // log100001 = 19.9x, 2^20 = 1048576
int lazy[1048576];

int MAX_N = 100000;
int MAX_TREE = 1048576;


long long init(int node, int begin, int end) {
  // begin, end : node 가 포함하는 범위
  // 예 : 2번 노드가 범위 0~3포함 node=2, begin=0, end=3
  // 8개 데이터 담는 트리 초기화 : init(1, 0, 7)
  if(begin == end) return tree[node] = data[begin];
  int mid = (begin + end) / 2;
  return tree[node] = init(node * 2, begin, mid) + init(node * 2 + 1, mid + 1, end);
}

int sum(int node, int begin, int end, int left, int right) {
  // begin, end : node 가 포함하는 범위
  // left, right : 합을 구하고자하는 범위
  // 1.[begin, end] 범위가 [left, right]에 전혀 겹치지 않음
  // 2.[begin, end] 범위가 [left, right]에 포함
  // 3.[begin, end] 범위가 [left, right]에 일부분 겹치는 경우
  if(end < left || right < begin) return 0;
  if(left <= begin && end <= right) return tree[node];
  
  int mid = (begin + end) / 2;
  return sum(node * 2, begin, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int begin, int end, int index, int delta) {
  // index를 포함하는 모든 노드 delta 만큼 변경
  // begin, end : node 가 포함하는 범위
  if (index < begin || end < index) return;
  tree[node] += delta;
  if (begin == end) return;
  int mid = (begin + end) / 2;
  update(node * 2, begin, mid, index, delta);
  update(node * 2 + 1, mid + 1, end, index, delta);
}

void update_lazy(int node, int begin, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end - begin + 1) * lazy[node];
        if (begin != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

int sum_lazy(int node, int begin, int end, int left, int right) {
  // begin, end : node 가 포함하는 범위
  // left, right : 합을 구하고자하는 범위
  // 1.[begin, end] 범위가 [left, right]에 전혀 겹치지 않음
  // 2.[begin, end] 범위가 [left, right]에 포함
  // 3.[begin, end] 범위가 [left, right]에 일부분 겹치는 경우
  update_lazy(node, begin, end);

  if(end < left || right < begin) return 0;
  if(left <= begin && end <= right) return tree[node];
  
  int mid = (begin + end) / 2;
  return sum(node * 2, begin, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update_range(int node, int begin, int end, int left, int right, int delta) {
  update_lazy(node, begin, end);
  if (end < left || right < begin) return;
  if (left <= begin && begin <= right) {
    tree[node] += (end - begin + 1) * delta;
    if (begin != end) {
      lazy[node * 2] += delta;
      lazy[node * 2 + 1] += delta;
    }
    return;
  }
  int mid = (begin + end) / 2;
  update_range(node * 2, begin, mid, left, right, delta);
  update_range(node * 2 + 1, mid + 1, end, left, right, delta);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int minByCap(int a, int b, int c, int cap) {
    int min = 12345678;
    if(a < min) min = a;
    if(b < min) min = b;
    if(c < min) min = c;
    return min < cap ? min : cap;
}

void initData() {
    N = Q = SUM = 0;
    for(int i = 1; i <= MAX_N; i++) {
        p[0][i] = p[1][i] = p[2][i] = 0;
        data[i] = 0;
    }
    for(int i = 1; i <= MAX_TREE; i++) {
      tree[i] = lazy[i] = 0;
    }
}

void fill(int x, int y, int k, int c) {
    for(int i = x; i <= y; i++) {
        p[k - 1][i] += c;
    }
}

void sell(int x, int c) {
    int toSell = minByCap(p[0][x], p[1][x], p[2][x], c);

    p[1][x] -= toSell;
    p[2][x] -= toSell;
    p[3][x] -= toSell;
    p[0][x] += toSell;
}

void check(int x, int y) {
    for(int i = x; i <= y; i++) {
        SUM += p[0][i];
    }
}

int main() {
    int t, q;
    int qc;
    int x, y, k, c;
    scanf("%d", &T);
    for(t = 1; t <= T; t++) {
        initData();
        scanf("%d %d", &N, &Q);
        for(q = 1; q <= Q; q++) {
            scanf("%d", &qc);
            if(qc == 1) {
                scanf("%d %d %d %d", &x, &y, &k, &c);
                fill(x, y, k, c);
            } else if(qc == 2) {
                scanf("%d %d", &x, &y);
                sell(x, y);
            } else {
                scanf("%d %d", &x, &y);
                check(x, y);
            }
        }
        printf("#%d %d\n", t, SUM);
    }
    return 1;
}