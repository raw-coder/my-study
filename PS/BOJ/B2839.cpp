#include <stdio.h>

int main() {
  int N, b;
  scanf("%d", &N);

  while(N - b * 3 > 0) {
    int a = (N - b * 3) % 5;
    if(a == 0) {
      printf("%d", (N - b * 3) / 5 + b); 
      return 0;
    }
    b++;
  }
  if(N - b * 3 == 0) {
    printf("%d", b);
  } else {
    printf("%d", -1);
  }
  
  return 0;
}