/*
BOJ 2667 단지 번호 붙이기

DFS
*/
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX_SIZE 25

using namespace std;

int N, group = 0;
bool map[MAX_SIZE + 1][MAX_SIZE + 1];
bool isVisited[MAX_SIZE + 1][MAX_SIZE + 1];
vector<int> sizes;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int x, int y) {
  isVisited[x][y] = true;
  sizes[group]++;
  int i, nextX, nextY;
  for(i = 0; i < 4; i++) {
    nextX = x + dx[i];
    nextY = y + dy[i];
    if(nextX >= 1 && nextX <= N && nextY >= 1 && nextY <= N && !isVisited[nextX][nextY] && map[nextX][nextY]) {
      dfs(nextX, nextY);
    }
  }
}

int main() {
  int i, j, m;
  
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    for(j = 1; j <= N; j++) {
      scanf("%1d", &m);
      map[i][j] = (m == 1 ? true : false);
    }
  }
  for(i = 1; i <= N; i++) {
    for(j = 1; j <= N; j++) {
      if(map[i][j] && !isVisited[i][j]) {
        sizes.push_back(0);
        dfs(i, j);
        group++;
      }
    }
  }
  printf("%d\n", group);
  sort(sizes.begin(), sizes.end());
  for(int size: sizes) {
    printf("%d\n", size);
  }
  return 0;
}

/*
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000
---
3
7
8
9
---

25
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
1010101010101010101010101
0101010101010101010101010
--- 
312
1
...
1

*/
