/*
BOJ 11721 열개씩 끝어 출력

scanf 문자열 마지막에 \0 입력됨
*/
#include <stdio.h>

int main() {
  char str[101] ;
  scanf("%s", str);
  int i = 0;
  while(1 == 1) {
    if(str[i] == '\0') break;
    printf("%c", str[i++]);
    if(i % 10 == 0) printf("\n");
  }
  return 0;
}