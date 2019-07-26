/*
BOJ 10451 순열 사이클

dfs 로 순회하고 순회 시작시 방문하지 않은 경우 count ++ 처리
*/
#include <stdio.h>
#include <vector>

#define MAX_NODES 1000

using namespace std;

vector<int> edges[MAX_NODES + 1];
bool isVisited[MAX_NODES + 1];

void dfs(int node) {
  isVisited[node] = true;
  for(int next: edges[node]) {
    if(!isVisited[next]) dfs(next);
  }
}

int main() {
  int T, N, u, i ;
  int count = 0;
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
      scanf("%d", &u);
      edges[i].push_back(u);
    }
    for(i = 1; i <= N; i++) {
      if(!isVisited[i]) {
        count++;
      }
      dfs(i);
    }
    printf("%d\n", count);
    for(i = 1; i <= N; i++) {
      count = 0;
      isVisited[i] = false;
      while(!edges[i].empty()) edges[i].pop_back();
    }
  }
  return 0;
}