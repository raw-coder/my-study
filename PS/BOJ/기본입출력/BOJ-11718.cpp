/*
BOJ 11718
그대로 출력하기
with scanf

scanf("%[^\n]) : \n 나올때까지 입력받은(공백 포함)
getchar()
*/
#include <stdio.h>

int main() {
  char s[101];
  while(scanf("%[^\n]", s) != -1) {
    getchar();
    printf("%s\n", s);
  }
  return 0;
}