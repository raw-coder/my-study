/*
BOJ 1927 min heap

priority queue를 이용한 풀이
*/

#include <stdio.h>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
  int t, n;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    if(n == 0) {
      if(pq.empty()) {
        printf("0\n");
      } else {
        printf("%d\n", pq.top());
        pq.pop();
      }
    } else {
      pq.push(n);
    }
  }
  return 0;
}
