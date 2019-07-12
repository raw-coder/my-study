/*
BOJ 10951
입력 필드 EOF 처리
char -> int

main 함수 return 0; --> 정상 종료
*/
#include <stdio.h>
int a, b;
int main() {
  while(scanf("%d %d", &a, &b) != EOF) {
    printf("%d\n", a + b);
  }
  return 0;
}