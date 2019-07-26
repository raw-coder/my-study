/*
BOJ 11724 연결 요소의 개수
*/
#include <stdio.h>
#include <vector>
#define MAX_NODES 1000
using namespace std;

vector<int> edges[MAX_NODES + 1];
bool isVisited[MAX_NODES + 1];
int N, M;

void dfs(int node) {
  isVisited[node] = true;
  for(int next : edges[node]) {
    if(!isVisited[next]) {
      dfs(next);
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);
  int i, u, v;
  int count = 0;
  for(i = 1; i <= M; i++) {
    scanf("%d %d", &u, &v);
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for(i = 1; i <= N; i++) {
    if(!isVisited[i]) {
      count++;
      dfs(i);
    }
  }

  printf("%d", count);
  return 0;
}