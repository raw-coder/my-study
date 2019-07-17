#include <stdio.h>
long factorial(int n) {
  if(n == 0) return 1;
  return n * factorial(n - 1);
}

int main() {
  int i;
  for(i = 1; i <= 10; i++) {
    printf("%d! = %ld \n", i, factorial(i));
  }
  return 0;
}