/*
BOJ 6549 히스토그램에서 가장 큰 직사각형

스택을 이용한 풀이
TODO : 이해하기
*/
#include <stdio.h>
#include <stack>

using namespace std;

int h[100001];

int main() {
  int n, i;
  while(1 == 1) {
    scanf("%d", &n);
    if(n == 0) break;
    for(i = 1; i <= n; i++) {
      scanf("%d", &h[i]);
    }

    stack<int> s;
    int ans = 0;
    for(i = 1; i <= n; i++) {
      int left = i;
      while(!s.empty() && h[s.top()] > h[i]) {
        int height = h[s.top()];
        s.pop();
        int width = i;
        if(!s.empty()) width = (i - s.top() - 1);
        if(ans < width * height) ans = width * height; 
      }
      s.push(i);
    }
    while(!s.empty()) {
      int height = h[s.top()];
      s.pop();
      int width = n;
      if(!s.empty()) width = (n - s.top() - 1);
      if(ans < width * height) ans = width * height;
    }
    printf("%d\n", ans);
  }
  return 0;
}