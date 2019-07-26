/*
BOJ 1260 DFS BFS

*/
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> edges[1001];
bool visited[1001];

void dfs(int node) {
  visited[node] = true;
  printf("%d ", node);
  
  int i;
  for(int child: edges[node]) {
    if(!visited[child]) {
      dfs(child);
    }
  }
}

void bfs(int node) {
  queue<int> q;
  q.push(node);
  visited[node] = true;

  while(!q.empty()) {
    int parent = q.front();
    q.pop();
    printf("%d ", parent);
    for(int child : edges[parent]) {
      if(!visited[child]) {
        q.push(child);
        visited[child] = true;
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &V);
  int i, from, to;
  for(i = 1; i <= M; i++) {
    scanf("%d %d", &from, &to);
    edges[from].push_back(to);
    edges[to].push_back(from);
  }
  for(i = 1; i <= N; i++) {
    sort(edges[i].begin(), edges[i].end());
  }
  dfs(V);
  printf("\n");
  for(i = 1; i <= N; i++) {
    visited[i] = false;
  }
  bfs(V);
  return 0;
}