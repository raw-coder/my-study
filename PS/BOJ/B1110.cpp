#include <stdio.h>

int main() {
  int N, c = 1;
  scanf("%d", &N);
  int prv = N;
  while(1==1) {
    int next;
    if(prv < 10) {
      next = prv * 10 + prv; 
    } else {
      next = (prv % 10) * 10 + ((prv % 10 + prv / 10) % 10);
    }    
    if(next == N) {
      printf("%d", c);
      return 0;
    } else {
      prv = next;
      c++;
    }
  }
  
}