/*
BOJ 9012 괄호

1. (, ) 갯수 동일
예외 : ())(()
*/
#include <stdio.h>
#include <stack>

using namespace std;

int main() {
  int t;
  char c[51];
  scanf("%d", &t);
  while(t--) {
    stack<char> s;
    scanf("%s", c);
    int i = 0;
    while(c[i] != '\0') {
      if(c[i] == '(') {
        s.push(c[i]);
      } else {
        if(s.size() > 0) {
          s.pop();
        } else {
          printf("NO\n");
          break;
        }
      }
      i++;
    }
    if(c[i] == '\0') {
      s.size() > 0 ? printf("NO\n") : printf("YES\n");
    }
  }
  return 0;
}