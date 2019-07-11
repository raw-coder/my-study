#include <stdio.h>

int main() {
  char s[101];  
  int i = 0;
  while (scanf("%s", s) != -1) {
    printf("%s ", s);
  }
  printf("\n");
  return 0;
}