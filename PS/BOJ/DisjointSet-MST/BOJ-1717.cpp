/*
BOJ 1717 집합의 표현

union-find 자료 구조 사용
구현시 참고 : https://bowbowbow.tistory.com/26
*/
#include <stdio.h>
#include <vector>

using namespace std;

struct DisjointSet {
  vector<int> parent, rank;
  DisjointSet(int n) : parent(n), rank(n, 1) {
    for(int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) rank[v]++;
  }
};

int main() {
  int n, m, o, a, b;
  scanf("%d %d", &n, &m);
  DisjointSet set = DisjointSet(n + 1);
  while(m--) {
    scanf("%d %d %d", &o, &a, &b);
    if(o == 0) {
      set.merge(a, b);
    } else {
      printf("%s\n", set.find(a) == set.find(b) ? "YES" : "NO");
    }
  }
  return 0;
}