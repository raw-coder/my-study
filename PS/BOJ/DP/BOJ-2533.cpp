/*
BOJ 2533 사회망 서비스(SNS)

dp[i][0 or 1] = root i 인 트리의 최소 얼리어댑터 수 , 1 : 얼리어댑터, 0 : 보통
*/
#include <stdio.h>
#include <vector>
#define MAX_NODES 1000000
using namespace std;

vector<int> edges[MAX_NODES + 1];
bool isVisited[MAX_NODES + 1];
int dp[MAX_NODES + 1][2];

int min(int a, int b) {
  return a < b ? a : b;
}

void dfs(int node, bool isEarlyAdapter) {

  isVisited[node] = true;
  if(isEarlyAdapter) {
    dp[node][0] = 1;
  }
  

  if(edges[node].size() == 0) {
    dp[node][0] = 0;
    dp[node][1] = 1;
    return;
  }

  for(int next: edges[node]) {
    if(!isVisited[next]) {
      if(isEarlyAdapter) {
        dfs(next, false);
      } else {
        dfs(next, true);
      }
    }
  }
  

  isVisited[node] = false;

}

int main() {
  int N, u, v;
  scanf("%d", &N);
  while(scanf("%d %d", &u, &v) != -1) {
    edges[u].push_back(v);
  }
  printf("%d\n", min(dfs(1, true), dfs(1, false)));
  return 0;
}