#include <stdio.h>
#include <vector>

using namespace std;

struct UnionFind {
  vector<int> parent, rank;
  UnionFind(int n) : parent(n), rank(n, 1) {
    for(int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }
  int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) rank[v]++;
  }
};

int main() {
  int n, m, o, a, b;
  scanf("%d %d", &n, &m);
  UnionFind uf(n);
  while(m--) {
    scanf("%d %d %d", &o, &a, &b);
    if(o == 1) {
      printf("%s\n", uf.find(a) == uf.find(b) ? "YES": "NO");
    } else {
      uf.merge(a, b);
    }
  }
  return 0;
}