/*
피보나치 수열
fib(n)
= 0, if n = 0
= 1, if n = 1
= fib(n - 1) + fib(n - 2), o/w
*/
#include <stdio.h>

int fib(int n) {
  printf("fib function is called with parameter %d\n", n);
  if(n == 0) return 0;
  if(n == 1) return 1;
  return fib(n - 1) + fib(n - 2); 
}

int main() {
  int i;
  // for(i = 0; i <= 15; i++) {
  //   printf("%d\n", fib(i));
  // }
  fib(7);
  return 0;
}