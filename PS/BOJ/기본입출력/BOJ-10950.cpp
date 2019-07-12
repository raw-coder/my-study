#include <stdio.h>

int n;

int main() {
  int i, a, b;
  scanf("%d", &n);

  for(i = 1; i <= n; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
  }
}