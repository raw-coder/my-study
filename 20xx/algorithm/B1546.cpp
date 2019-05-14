#include <stdio.h>

int main() {
  int N, i, s, sum = 0, max = -1;
  double avg;
  scanf("%d", &N);

  for(i = 0; i < N; i++) {
    scanf("%d", &s);
    sum += s;
    if(s > max) {
      max = s;
    }
  }
  printf("%5.2f", (double) sum * 100 / N / max);
  return 0;
}