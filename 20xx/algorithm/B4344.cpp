#include <stdio.h>

int main() {
  int C, i, j;
  scanf("%d", &C);
  for(i = 0; i < C; i++) {
    int N, s[1001] = {-1}, sum = 0, over = 0;
    double avg;
    scanf("%d", &N);
    for(j = 0; j < N; j++) {
      scanf("%d", &s[j]);
      sum += s[j];
    }
    avg = (double) sum / N;
    for(j = 0; j < N; j++) {
      if(s[j] > avg) {
        over++;
      }
    }    
    printf("%.3f%% \n", (double)over / N * 100);
  }
  return 0;
}