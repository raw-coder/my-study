/*
BOJ 10799 쇠막대기

stack 사용
두글자씩 읽어서 () 만났을때
  count += stack.size()
() 아닌경우
  ( 가 첫글자이면 stack.push
  ) 가 첫글자이면 stack.pop; count++;
*/
#include <stdio.h>
#include <stack>

using namespace std;

int main() {
  stack<char> s;
  char c[100001];
  int i = 0;
  int count = 0;
  scanf("%s", c);
  while(c[i] != '\0') {
    if(c[i] == '(') {
      if(c[i+1] == ')') {
        count += s.size();
        i += 2;
        continue;
      } else {
        s.push(c[i]);
      }
    } else {
      s.pop();
      count++;
    }
    i++;
  }
  printf("%d", count);
}