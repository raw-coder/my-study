/*
10953
*/
#include <stdio.h>

int main() {
  int n, i;
  char str[4];
  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    scanf("%s", str);
    printf("%d\n", (str[0] - '0') + (str[2] - '0'));
  }
  return 0;
}