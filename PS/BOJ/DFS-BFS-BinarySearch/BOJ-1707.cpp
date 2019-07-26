/*
BOJ 1707 이분 그래프

- DFS 로 컬러링 후 인접한 두 점의 색깔이 다른지 확인
*/
#include <stdio.h>
#include <vector>

using namespace std;

#define MAX_NODES 20000

vector<int> edges[MAX_NODES + 1];
bool isVisited[MAX_NODES + 1];
int color[MAX_NODES + 1];

void dfs(int node, int c) {
  isVisited[node] = true;
  color[node] = c;
  for(int next: edges[node]) {
    if(!isVisited[next]) {
      dfs(next, c * -1);
    }
  }
}

int main() {
  int K, V, E, i;
  int u, v;
  bool isBipartite = true;
  scanf("%d", &K);
  while(K--) {
    scanf("%d %d", &V, &E);
    for(i = 1; i <= E; i++) {
      scanf("%d %d", &u, &v);
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    for(i = 1; i <= V; i++) {
      if(!isVisited[i]) {
        dfs(i, 1);
      }
    }
    for(i = 1; i <= V; i++) {
      for(int next: edges[i]) {
        if(i != next && color[i] == color[next]) {
          isBipartite = false;
          break;
        }
      }
    }
    printf("%s\n", isBipartite ? "YES" : "NO");
    isBipartite = true;
    for(i = 1; i <= V; i++) {
      isVisited[i] = false;
      while(!edges[i].empty()) {
        edges[i].pop_back();
      }
    }
  }
  return 0;
}