/*
BOJ 2696 중앙값 구하기

max_heap, min_heap에 숫자 하나씩 나누어 입력하면서 median값 갱신
*/
#include <stdio.h>
#include <queue>
using namespace std;

int main() {
  int t, m, n, medians[10000] = {0, }, i;

  scanf("%d", &t);
  while(t--) {
    priority_queue<int, vector<int>, less<int> > max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
    int count = 1;
    int med = 0;
    scanf("%d", &m);

    while(m--) {
      scanf("%d", &n);
      if(n > med) {
        min_heap.push(n);
      } else {
        max_heap.push(n);
      }
      
      // heap size 조정 (|max_heap size - min_heap size <= 1)
      if(max_heap.size() > min_heap.size() + 1 ) {
        min_heap.push(max_heap.top());
        max_heap.pop();
      } else if(min_heap.size() > max_heap.size() + 1) {
        max_heap.push(min_heap.top());
        min_heap.pop();
      }

      if(max_heap.size() == min_heap.size()) {
        med = (max_heap.top() + min_heap.top()) / 2;
      } else {
        med = max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top();
        medians[count++] = med;
      }
    }

    printf("%d\n", count - 1);
    for(i = 1; i <= count - 1; i++) printf("%d ", medians[i]);
    printf("\n");
  }
  return 0;
}
