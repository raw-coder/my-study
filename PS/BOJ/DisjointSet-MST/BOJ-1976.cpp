/*
BOJ 1976 여행 가자

UnionFind 를 이용한 풀이
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
  int find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v) {
    u = parent[u];
    v = parent[v];
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) rank[v]++;
  }
};

int main() {
  int n, m, adj;
  scanf("%d", &n);
  scanf("%d", &m);
  UnionFind uf(n + 1);
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      scanf("%d", &adj);
      if(adj == 1) uf.merge(i + 1, j + 1);
    }
  }
  bool isConneted = true;
  int city;
  scanf("%d", &city);
  int root = uf.find(city);
  for(int i = 0; i < m - 1; i++) {
    scanf("%d", &city);
    if(root != uf.find(city)) {
      isConneted = false;
      break;
    }
  } 
  printf("%s\n", isConneted ? "YES" : "NO");
  return 0;
}