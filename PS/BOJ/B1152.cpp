// 백준 1152 단어의 개수

#include <stdio.h>

int main() {
  int i = 0, cnt = 0;
  int isWord = 0;
  char c[1000001];
  while (1 == 1) {
    scanf("&c", &c);
    if(c[0] == -1) break;
    while (1 == 1) {
      if(c[i] == ' ') {
        cnt += isWord;
        isWord = 0;
      } else {
        isWord = 1;
      }
    }
    printf("isword : %d\n", isWord);
    printf("cnt : %d\n", cnt);
  }
  printf("%d", cnt);
  return 0;
}