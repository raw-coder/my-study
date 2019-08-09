/*
BOJ 4963 섬의 개수

DFS
*/

#include <stdio.h>
#define MAX_SIZE 50

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int count = 0;
int map[MAX_SIZE +1][MAX_SIZE +1];
bool isVisited[MAX_SIZE +1][MAX_SIZE +1];
int w, h;

void dfs(int x, int y) {
  isVisited[x][y] = true;
  int i, nextX, nextY;
  for(i = 0; i < 8; i++) {
    nextX = x + dx[i];
    nextY = y + dy[i];
    if(nextX < 1 || nextX > h || nextY < 1 || nextY > w) continue;
    if(!isVisited[nextX][nextY] && map[nextX][nextY] == 1) {
      dfs(nextX, nextY);
    }
  }
}

int main() {
  int i, j;
  while(true) {
    scanf("%d %d", &w, &h);
    if(w == 0 && h == 0) break;
    for(i = 1; i <= h; i++) {
      for(j = 1; j <= w; j++) {
        scanf("%d", &map[i][j]);
      }
    }

    for(i = 1; i <= h; i++) {
      for(j = 1; j <= w; j++) {
        if(!isVisited[i][j] && map[i][j] == 1) {
          count++;
          dfs(i, j);
        }
      }
    }
    printf("%d\n", count);
    for(i = 1; i <= h; i++) {
      for(j = 1; j <= w; j++) {
        map[i][j] = 0;
        isVisited[i][j] = false;
      }
    }
    count = 0;
  }
  return 0;
}