/*
BOJ 11437 LCA
*/
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> edges[50001];
int isVisited[50001];
int levels[50001];
int parents[50001];

void dfs(int node, int l, int p) {
  isVisited[node] = true;
  levels[node] = l;
  parents[node] = p;

  for(int next : edges[node]) {
    if(!isVisited[next]) {
      dfs(next, l + 1, node);
    }
  }
}

int ca(int u, int v) {
  if(parents[u] == parents[v]) return parents[v];
  while(parents[u] != parents[v]) {
    if(levels[u] > levels[v]) swap(u, v);
    v = parents[v];
  }
  return u == v ? v : parents[v];
}

int main() {
  int n, m, u, v;
  scanf("%d", &n);
  for(int i = 1; i <= n - 1; ++i) {
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  dfs(1, 0, 0);
  scanf("%d", &m);
  for(int i = 1; i <= m; ++i) {
    scanf("%d %d", &u, &v);
    printf("%d\n", ca(u, v));
  }
  return 0;
}