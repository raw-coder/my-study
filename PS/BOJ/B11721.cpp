#include <stdio.h>

int main() {
  char str[101] = {'\0'};
  int i = 0;
  scanf("%s", str);
  while(str[i] != '\0') {
    printf("%c", str[i]);
    i++;
    if(i % 10 == 0) {
      printf("\n");
    }
  }
  return 0;
}