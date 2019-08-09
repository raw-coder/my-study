/*
BOJ 1963 소수 경로

소수의 성질(에라토스테네스 체)
BFS 를 사용한 풀이
*/
#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAX_NUM 9999

using namespace std;

bool isNotPrime[MAX_NUM + 1];
bool visited[MAX_NUM + 1];

void initPrime() {
  int i, j;
  isNotPrime[1] = true;
  for(i = 2; i <= MAX_NUM; i++) {
    if(isNotPrime[i]) continue;
    for(j = i * 2; j <= MAX_NUM; j += i) {
      isNotPrime[j] = true;
    }
  }
}

int bfs(int number, int target) {
  visited[number] = true;
  queue<pair<int, int>> q;
  q.push(make_pair(number, 0));
  int d3, d2, d1, d0;
  int newNum;
  int i;
  int ret = -1;

  while(!q.empty()) {
    pair <int, int> parentNode = q.front(); 
    q.pop();
    int parent = parentNode.first;
    int depth = parentNode.second;
    
    if(parent == target) {
      ret = depth;
      break;
    }
    d3 = parent / 1000;
    d2 = (parent - d3 * 1000) / 100;
    d1 = (parent - d3 * 1000 - d2 * 100) / 10;
    d0 = (parent - d3 * 1000 - d2 * 100 - d1 * 10);

    // 1000의 자리
    for(i = 1; i <= 9; i++) {
      newNum = parent - 1000 * d3 + 1000 * i;
      if(!visited[newNum] && !isNotPrime[newNum]) {
        visited[newNum] = true;
        q.push(make_pair(newNum, depth + 1));
      }
    }
    // 100의 자리
    for(i = 0; i <= 9; i++) {
      newNum = parent - 100 * d2 + 100 * i;
      if(!visited[newNum] && !isNotPrime[newNum]) {
        visited[newNum] = true;
        q.push(make_pair(newNum, depth + 1));
      }
    }
    // 10 의 자리
    for(i = 0; i <= 9; i++) {
      newNum = parent - 10 * d1 + 10 * i;
      if(!visited[newNum] && !isNotPrime[newNum]) {
        visited[newNum] = true;
        q.push(make_pair(newNum, depth + 1));
      }
    }
    // 1의 자리
    for(i = 0; i <= 9; i++) {
      newNum = parent - d0 + i;
      if(!visited[newNum] && !isNotPrime[newNum]) {
        visited[newNum] = true;
        q.push(make_pair(newNum, depth + 1));
      }
    }
  }
  return ret;
}

int main() {
  initPrime();
  int T, from, to, steps, i;
  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &from, &to);
    steps = bfs(from, to);
    if(steps == -1) {
      printf("Impossible\n");
    } else {
      printf("%d\n", steps);
    }
    for(i = 1000; i <= MAX_NUM; i++) {
      visited[i] = false;
    }
  }
  return 0;
}