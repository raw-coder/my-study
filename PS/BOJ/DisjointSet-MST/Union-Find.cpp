/*
Union Find Sample
*/

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
  // find a root node of u
  int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);  // path compression
  }
  // union two sets which have u or v
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v; // optimize by rank
    if(rank[u] == rank[v]) rank[v]++;
  }
};
int main() {
  int n, m, o, a, b;
  scanf("%d %d", &n, &m);
  UnionFind uf(n);
  while(m--) {
    scanf("%d %d %d", &o, &a, &b);
    if(o == 0) {
      uf.merge(a, b);
    } else {
      printf("%s\n", uf.find(a) == uf.find(b) ? "YES" : "NO");
    }
  }
  return 0;
}