/*
BOJ 1963 소수 경로

소수의 성질(에라토스테네스 체)
BFS 를 사용한 풀이
*/
#include <stdio.h>
#include <queue>
#include <set>
#define MAX_NUM 10000

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

void bfs(int node) {
  queue<int> q;
  q.push(node);
  visited[node] = true;
  
  int i, j;
  while(!q.empty()) {

    q.pop();

    for(i = 1; i <= 1000; i *= 10) {
      for(j = 0; j <= 9; j++) {

      }
    }
  }
}

bool is3digitsSame(int a, int b) {
  int arrA[4], arrB[4];
  int i, j;
  int count = 0;
  set<int> set;

  for(i = 3; i > 0; i++) {
    set.insert(a % 10);
    a /= 10;
    // arrB[i] = b % 10;
    // b /= 10;
  }
  for(i = 0; i < 4; i++) {
    for(j = 0; j < 4; j++) {
      if(arrA[i] == arrB[j]) {
        count++;
      }
    }
  }


}

int main() {
  initPrime();

  return 0;
}