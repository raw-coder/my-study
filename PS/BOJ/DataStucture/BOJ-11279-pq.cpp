/*
BOJ 11279 최대힙

priority queue 를 이용한 풀이
*/
#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int> q;

int main() {
  int n, num;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &num);
    if(num == 0) {
      if(q.empty()) {
        printf("0\n");
      } else {
        printf("%d\n", q.top());
        q.pop();
      }
    } else {
      q.push(num);
    }
  }
  return 0;
}