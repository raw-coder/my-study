/*
BOJ 1197 최소 스패닝 트리

Kruskal algorithm 을 이용한 풀이
*/
#include <stdio.h>
#include <vector>
#include <algorithm> 

using namespace std;

struct UnionFind {
  vector<int> parent, rank;
  UnionFind(int n) : parent(n), rank(n, 1) {
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
    if(rank[u] > rank[v]) swap(u, v);
    parent[u] = v;
    if(rank[u] == rank[v]) rank[v]++;
  }
};

struct Edge {
  int u, v, c;
  Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}
};

bool compare(Edge x, Edge y) {
  return x.c < y.c;
}

int main() {
  int v, e, a, b, c;
  scanf("%d %d", &v, &e);
  vector<Edge> edges;
  UnionFind uf(v + 1);
  for(int i = 0; i < e; i++) {
    scanf("%d %d %d", &a, &b, &c);
    edges.push_back(Edge(a, b, c));
  }
  sort(edges.begin(), edges.end(), compare);
  int n = 0, sum = 0;
  for(int i = 0; i < e; i++) {
    if(uf.find(edges[i].u) != uf.find(edges[i].v)) {
      uf.merge(edges[i].u, edges[i].v);
      ++n;
      sum += edges[i].c;
    }
    if(n == (v - 1)) break;
  }
  printf("%d\n", sum);
  return 0;
}